#!/bin/bash
# This file is part of Natron.
# Copyright (C) 2019 Guillaume Roguez
#
# Natron is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Natron is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>

# Can be overridden at convenience
LOGDIR=$NATRON_BUILD_DIR/log

start_build() {
    printf "> %-20s" "$1"
	[ -d "$LOGDIR" ] || mkdir -p $LOGDIR
    touch "$LOGDIR/$1".stamp
    exec 3>&1 4>&2 1>"$LOGDIR/$1".log 2>&1
	cmd_start=$(date +%s)
}

end_build() {
	cmd_end=$(date +%s)
    find "$SDK" -newer "$LOGDIR/$1".stamp > "$LOGDIR/$1"-files.txt
    rm "$LOGDIR/$1".stamp
    exec 1>&3 2>&4
	local duration=$(($cmd_end - $cmd_start))
	if $2; then
		echo "ok - $(print_duration $duration)" 
	else
		echo "failed after $(print_duration $duration)"
		echo "*** $1 has failed, see log file '$LOGDIR/$1.log' ***"
	fi
}

start_stop_command() {
	local pkg="$1"
	local cmd="${*:2}"

	start_build $pkg
	
	if eval "$cmd"; then
		end_build $pkg true
		return
	fi
	
	end_build $pkg false
	exit 1
}

# Override me
process() {
	true
}

print_duration() {
	echo -n "$((($1/3600)%60))h $((($1/60)%60))mn $(($1%60))s"
}

main() {
	echo "=== Build started the $(date +%x) at $(date +%X)"
	local time_start=$(date +%s)
	process || true
	local time_end=$(date +%s)
	local duration=$(($time_end - $time_start))
	echo "=== Total duration: $(print_duration $duration)"
}

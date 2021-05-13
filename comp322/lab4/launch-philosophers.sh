#!/bin/bash
## Script that launches the specified number of philosopher instances



# Delete an existing process group file if exists
rm -f pgroup.txt

# Launch dining-p program instances with constant seats 
# but varying positions 
SEATS=$1
for i in $(seq 0 $(expr $SEATS - 1)); do
    ./dining-p $SEATS $i &
done

# Execute a script to generate another script that will send SIGTERM 
# to the group of philosphers this script launched
cd misc
./generate-kill.sh
cd ..

# To kill the philosophers, execute ./kill_philosophers from
# the lab root

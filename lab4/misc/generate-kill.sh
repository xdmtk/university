#!/bin/bash
## Quick script to generate a kill script for the philosphers process group 



# Pull the Group ID via some ps output manipulation
GROUP_ID=$(ps axo command,pgrp | grep "./dining-p" | tr -s ' ' | cut -d ' ' -f 4 | head -1)

# Create a kill script to exit kill the philosopher group
echo -e "kill -TERM -- -$GROUP_ID; rm kill_philosophers; rm -f pgroup.txt" > ../kill_philosophers

# Make the script executable
chmod +x ../kill_philosophers


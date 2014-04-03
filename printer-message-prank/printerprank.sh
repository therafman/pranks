#!/bin/bash

# NOT TESTED
function sendPJL {
    MSG="
    \033%-12345X
    @PJL RDYMSG DISPLAY=\"$2\"
    \033%-12345X
    "
    printf "$MSG" | nc $1 9100 #not sure if netcat will do this properly
}

echo "Changing ready message of printer $1 to $2..."
RESPONSE=`sendPJL "$1" "$2"`
echo "$RESPONSE" #todo check printer response for success/fail/empty
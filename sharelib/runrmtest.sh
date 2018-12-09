#!/bin/bash
resul=`make`
if [ $? -eq 0 ]
then 
        echo "yes"
else
        echo "no"
fi

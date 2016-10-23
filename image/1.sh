#!/bin/bash 
SCRIPT=`basename $0`
export CURPWD=$(cd `dirname $0`; pwd)
cd ${CURPWD};
make;./image

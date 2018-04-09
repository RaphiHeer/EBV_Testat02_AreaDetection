#!/bin/bash

# ***************************************************************************
#  
#                            ARM Deploy Script
#
#----------------------------------------------------------------------------
#
# 1. Pack ARM compilation
# 2. Deploy to remote target
# 3. Unpack and run on remote target
#           
# ***************************************************************************

#target IP address
TARGET_IP=192.168.1.10

#target user name
TARGET_USER=pi

#target password
TARGET_PASS=hslu

#path of binaries to be deployed
BINARY_PATH=arm-obj_rel/image_proc_agent

#agent configuration file
AGENT_CONFIG_FILE=ebvOption.conf

#current working dir
CURRENT_DIR=$(pwd)

#name of deploy folder
DEPLOY_FOLDER_NAME=ebvAgentDeploy

#name of deployed tar file
DEPLOY_FILE_NAME=$DEPLOY_FOLDER_NAME.tar

#destination folder to deploy
DESTINATION_FOLDER=/home/pi/tmp

echo Deploy ARM
echo 

echo Targe IP $TARGET_IP
echo Binary path $BINARY_PATH

COLLECTION_FOLDER_NAME=$CURRENT_DIR/$DEPLOY_FOLDER_NAME

echo "> Create deploy collection in $COLLECTION_FOLDER_NAME"

rm -f -R $COLLECTION_FOLDER_NAME
mkdir -p -v $COLLECTION_FOLDER_NAME
cp $AGENT_CONFIG_FILE $COLLECTION_FOLDER_NAME
cp $BINARY_PATH $COLLECTION_FOLDER_NAME

echo "> Create $DEPLOY_FILE_NAME"
tar -czf $DEPLOY_FILE_NAME $DEPLOY_FOLDER_NAME

echo "> Delete old files on target"
sshpass -p $TARGET_PASS ssh $TARGET_USER@$TARGET_IP "cd $DESTINATION_FOLDER && rm -f -R $DEPLOY_FOLDER_NAME && rm -f $DEPLOY_FILE_NAME"

echo "> Copy tar to target $TARGET_IP:$DESTINATION_FOLDER"
sshpass -p $TARGET_PASS scp $DEPLOY_FOLDER_NAME.tar "$TARGET_USER@$TARGET_IP:$DESTINATION_FOLDER"

echo "> Unpack on target"
sshpass -p $TARGET_PASS ssh $TARGET_USER@$TARGET_IP "cd $DESTINATION_FOLDER && tar -m -xzf $DEPLOY_FILE_NAME"

echo "> Stop running agent"
sshpass -p $TARGET_PASS ssh $TARGET_USER@$TARGET_IP "killall -q image_proc_agent"

echo "> Run deployed agent"
AGENT_FOLDER=$DESTINATION_FOLDER/$DEPLOY_FOLDER_NAME
sshpass -p $TARGET_PASS ssh $TARGET_USER@$TARGET_IP "cd $AGENT_FOLDER && ./image_proc_agent -f $AGENT_CONFIG_FILE"

if [ $? -ne 0 ]; then
	# Wait some time to show the errors.
	sleep 3
        echo "Run terminated with ERROR" >/dev/stderr
else
        echo "Run successfully finished!"
fi



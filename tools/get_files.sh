#!/bin/bash

# Check if the script is running with the two arguments
if [ $# -ne 3 ]; then
	echo "Usage: $0 <tag> <package_name> <package_json>"
	exit 1
fi

tag=$1
package_name=$2
package_json=$3

tag_version=$(basename "$tag")

mkdir temp

# Download the package file
wget https://github.com/JahazielLem/ArduinoCore-samd/releases/download/$tag_version/$package_name
mv $package_name ../IDE_Board_Manager/
# Download the json file
wget https://github.com/JahazielLem/ArduinoCore-samd/releases/download/$tag_version/$package_json
mv $package_json temp/
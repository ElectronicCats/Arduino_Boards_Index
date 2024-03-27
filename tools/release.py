import sys
import os
import json
import shutil

DEFAULT_PACKETS_FILE = "../package_electroniccats_index.json"
DEFAULT_TEMP_FOLDER = "temp"
DEFAULT_IDENT_JSON = 2
RELEASE_PACKAGE_ARCHITECTURE = "samd"

def read_json_file(file_name):
    with open(file_name, "r") as f:
        return json.load(f)

def write_json_file(file_name, data):
    with open(file_name, "w") as f:
        json.dump(data, f, indent=DEFAULT_IDENT_JSON)
    

def find_package_index(core_data, package_name):
    for index, package in enumerate(core_data["platforms"]):
        if package.get("architecture") == package_name:
            return index
    return None


def main():
    if len(sys.argv) < 2:
        print("Usage: python release_files.py <release_file>")
        sys.exit(1)

    release_file = sys.argv[1]
    print("Reading release file: %s" % release_file)
    
    release_data = read_json_file(os.path.join(DEFAULT_TEMP_FOLDER,release_file))
    core_data = read_json_file(DEFAULT_PACKETS_FILE)
    
    index_platform = None
    
    # Get the packages information
    # Get the first package, this contains the information of the package
    packates_data = core_data["packages"][0]
    
    index_platform = find_package_index(packates_data, RELEASE_PACKAGE_ARCHITECTURE)
    if index_platform is None:
        print("Error: Could not find platform %s" % RELEASE_PACKAGE_ARCHITECTURE)
        sys.exit(1)
    
    # Insert the release content into the package
    packates_data["platforms"].insert(index_platform, release_data)

    # Pack the release data into the package
    packet_json = {
        "packages": [packates_data]
    
    }
    write_json_file(DEFAULT_PACKETS_FILE, packet_json)
    print("Release data packed into %s" % DEFAULT_PACKETS_FILE)

    # Remove the temp folder
    shutil.rmtree(DEFAULT_TEMP_FOLDER)



if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print("Error: %s" % e)
        sys.exit(1)
    

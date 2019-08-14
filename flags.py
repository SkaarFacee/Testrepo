import argparse
import sys

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Script to find stats of users individually or as a group",allow_abbrev=False)
    parser.add_argument('-u',"--username", action='store', type=str,help="Enter the username")
    parser.add_argument('-d',"--data", action='store', type=str,help="Find the stats from a text file")
    args = parser.parse_args()
    if args.username:
        print(args.username)
    elif args.data:
        print(args.data)

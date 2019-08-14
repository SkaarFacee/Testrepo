import requests
import json
import collections
import re 

from secret import accessToken

headers = {"Authorization": "bearer "+ accessToken }

topic_query = """
        query ($name:String!){
        repositoryOwner(login:$name){
            login 
            ... on User {
            name
            avatarUrl
            pullRequests(last: 100){
                nodes{
                id
                createdAt
                additions
                deletions
                }
            }
            } 
        }
        } 
        """
suma=[]
sumd=[]
prcount=0

class pullRequestsData:

    def __init__(self, username):
        self.variables=dict({
            "name":str(username)
        })
        self.data = {}

    def getPRData(self):
        request = requests.post('https://api.github.com/graphql', json={'query': topic_query,"variables":self.variables},headers=headers)
        if(request.status_code == 200):
            result = request.json()           
            if(result['data']['repositoryOwner'] != None):
                self.data['username'] = result['data']['repositoryOwner']['login']
                self.data['name'] = result['data']['repositoryOwner']['name']
                prsdata = {}
                pradditions=0
                prdeletions=0
                for pr in result['data']['repositoryOwner']['pullRequests']['nodes']:
                    prdata = {}
                    if(re.match(r'^2019-10', pr['createdAt'])):
                        global prcount
                        prcount=prcount+1
                        prdata['createdAt'] = pr['createdAt']
                        prdata['additions'] = pr['additions']
                        add = pr['additions']
                        pradditions=int(pr['additions'])+pradditions
                        prdata['deletions'] = pr['deletions']
                        dels = pr['deletions']
                        prdeletions=int(pr['deletions'])+prdeletions
                        prsdata[pr['id']] = prdata
                        global suma
                        suma.append(int(add))
                        global sumd
                        sumd.append(int(dels))
                self.data['prsdata'] = prsdata
                print("\n")
                print("For the user "+ username +" this is the data")
                print("The total number of additons by this user is " +str(pradditions))
                print("The total number of deletions by this user is " +str(prdeletions)+ "\n")
            else:
                self.data['username'] = result['data']['repositoryOwner']

    def displayData(self):
        if(self.data['username'] != None):
            if(self.data['prsdata']):
                print(self.data)
            else:
                print("No PRs for Hacktoberfest")
        else:
            print("User doesn't exist")

if __name__ == "__main__":
    choice = input("To enter username enter 1 or to use existing data enter 2")
    if int(choice) == 1:
        username = input("Enter the GitHub username: ")
        prData = pullRequestsData(username)
        prData.getPRData()
        prData.displayData()
    
    elif int(choice) == 2:
        usersdata=open("data.txt", "r")
        if usersdata.mode == 'r':
            contents =usersdata.readlines()
            listcont2 = [x.replace('\n', '') for x in contents] 
            tot=len(usersdata.readlines())
            print (listcont2)
            for usname in listcont2:
                username=usname
                prData = pullRequestsData(username)
                prData.getPRData()
                prData.displayData()
        totala=0
        totald=0
        for a in range(0,len(suma)):
            totala=totala+int(suma[a])
        for b in range(0,len(sumd)):
            totald=totald+int(sumd[b])
        print("\n")
        print("Total additions " +str(totala))
        print("Total deletions " +str(totald))
        print("Total number of PR's " + str(prcount))
    else :
        print("Wrong option entered")


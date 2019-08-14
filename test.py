

query {
  repositoryOwner(login: "vchrombie") {
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
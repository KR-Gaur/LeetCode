class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        dic = {}
        for entry in paths:
            entriesInpath = entry.split(" ");
            # print( entriesInpath )
            directory = entriesInpath[0]
            # print(directory)
            entriesInpath.pop(0);
            for fileWithContent in entriesInpath:
                content = fileWithContent.split("(")[1].split(")")[0]
                # print(content)
                if content not in dic.keys():
                    dic[content] = []
                dic[content].append(str(directory+"/"+fileWithContent.split('(')[0]))
            
        ans = []
        for k in dic.keys():
            if( len(dic[k]) > 1 ):
                ans.append(dic[k])
        return ans 
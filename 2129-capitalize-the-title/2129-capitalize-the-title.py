class Solution:
    def capitalizeTitle(self, title: str) -> str:
        string = title.casefold().split(" ")
        ans = ""
        for st in string:
            if len(st) > 2:
                ans += st.capitalize() + " "
            else:
                ans += st + " "
        return ans[:-1]
class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        length = []
        for sent in sentences:
            length.append(len(sent.split(" ")))
        
        return max(length)
            
class Solution {
    public boolean wordBreak(String s, List<String> wrd) {
        Trie root = new Trie();
        for (String s1 : wrd) {
            Insert(root, s1);
        }
        
        int n = s.length();
        boolean[] record = new boolean[n + 1];
        
        record[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                String ss = s.substring(i, j + 1);
                if (Search(root, ss) && (record[j + 1] == true)) {
                    record[i] = true;
                    break;
                }
            }
        }
        
        if (record[0] == true) return true;
        return false;
    }
    
    private static boolean Search(Trie root, String str) {
        Trie ptr = root;
        int n = str.length();
        
        for (int i = 0; i < n; i++) {
            int idx = str.charAt(i) - 'a';
            if (ptr.trie[idx] == null) {
                return false;
            }
            ptr = ptr.trie[idx];
        }
        return (ptr.isEnd);
    }
    
    private static void Insert(Trie root, String str) {
        Trie ptr = root;
        int n = str.length();
        for (int i = 0; i < n; i++) {
            int idx = str.charAt(i) - 'a';
            if (ptr.trie[idx] == null) {
                ptr.trie[idx] = new Trie();
            }
            ptr = ptr.trie[idx];
        }
        ptr.isEnd = true;
    }
}

class Trie {
    Trie[] trie;
    boolean isEnd;

    Trie() {
        this.isEnd = false;
        this.trie = new Trie[26];
        for (Trie tn : trie) {
            tn = null;
        }
    }
}
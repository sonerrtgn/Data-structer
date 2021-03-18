// problem ->https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

public static int height(Node root) {
        if(root.left != null && root.right != null){
            return 1+(height(root.left) + height(root.right));
        }
        if(root.left != null){
            return 1+(height(root.left));
        }
        if(root.right != null){
            return 1+(height(root.right));
        }
        // left ve right boş demektir sıfır dönmelidir.
        return 0;
    }
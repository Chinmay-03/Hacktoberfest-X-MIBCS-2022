// with imaginary node we will counted as well
int widthOfBinaryTree(TreeNode *root)
        {
            if (!root)
                return 0;
            int maxwidth = 0;
            queue<pair<TreeNode*, int>> q;
            q.push({ root,0 });

            while (!q.empty())
            {
                int n = q.size();
                int index = q.front().second; //to make index 0;
                int first, last;
                for (int i = 0; i < n; i++)
                {
                    int currindex = q.front().second - index;
                    TreeNode *curr = q.front().first;
                    q.pop();
                    if (i == 0)
                        first = currindex;
                    if (i == n - 1)
                        last = currindex;
                    if (curr->left)
                        q.push({curr->left, (long long)currindex*2 + 1 });
                    if (curr->right)
                        q.push({curr->right, (long long)currindex*2 + 2 });
                }
                maxwidth = max(maxwidth, last - first + 1);
            }

            return maxwidth;
        }

#include <stdio.h>
#include <string.h>
int common[5000], first_edit[5000], cin_edit[5000],ans[5000];
char first[50000], cin[50000];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int num, comindex = 0,ansindex=0;
    scanf("%d", &num);
    getchar();
    int j = 0;
    scanf("%[^\n]", first);
    //printf("%s",first);
    int len = strlen(first);
    first[len] = ' ';
    int counter = 0, sum = 0, check = 0;
    for (int k = 0; k <= len; k++)
    {
        if (first[k] == ' '&& first[k-1]!=' ')
        {
            if (check == 0)
            {
                first_edit[counter] = sum;
            }
            else
            {
                first_edit[counter] = -sum;
            }
            check = 0;
            sum = 0;
            counter++;
        }
        else if (first[k] == '-')
        {
            check++;
        }
        else
        {
            sum = sum * 10 + first[k] - 48;
        }
    }
    int counterfirst = counter;
    //for (int y = 0; y < counterfirst; y++)
    //{
        //printf("%d ", first_edit[y]);
    //}
    //printf("\n");
    for (int h = 1; h < num; h++)
    {
        getchar();
        scanf("%[^\n]", cin);
        
        int l = strlen(cin);
        //printf("%d\n",l);
        counter = 0, sum = 0, check = 0;
        cin[l] = ' ';
        for (int k = 0; k <= l; k++)
        {
            if (cin[k] == ' '&&cin[k-1]!=' ')
            {
                if (check == 0)
                {
                    cin_edit[counter] = sum;
                }
                else
                {
                    cin_edit[counter] = -sum;
                }
                check = 0;
                sum = 0;
                counter++;
            }
            else if (cin[k] == '-')
            {
                check = 1;
            }
            else
            {
                sum = sum * 10 + cin[k] - 48;
            }
        }
        if (h == 1)
        {
            for (int i = 0; i < counterfirst; i++)
            {
                for (int c = 0; c < counter; c++)
                {
                    if (first_edit[i] == cin_edit[c])
                    {
                        int C = 0;
                        for (int f = 0; f < comindex; f++)
                        {
                            if (cin_edit[c] == common[f])
                            {
                                C = 1;
                                break;
                            }
                        }
                        if (C == 0)
                        {
                            common[comindex] = cin_edit[c];
                            comindex++;
                        }
                        C=0;
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<comindex;i++)
            {
                int find=0;
                for(int u=0;u<counter;u++)
                {
                    if(common[i]==cin_edit[u])
                    {
                        find=1;
                        break;
                    }
                }
                if(find==0)
                {
                    common[i]=6789;
                }
                else
                {
                    continue;
                }
            }
        }
        //for (int y = 0; y < counter; y++)
        //{
            //printf("%d ", cin_edit[y]);
        //}
        //printf("\n");

        
    }
for(int m=0;m<comindex;m++)
        {
            if(common[m]==6789)
            {
                continue;
            }
            else
            {
                ans[ansindex]=common[m];
                ansindex++;
            }
        }
        qsort(ans,ansindex,sizeof(int),cmp);
        for(int w=0;w<ansindex;w++)
        {
            if(w==0)
            {
                 printf("%d",ans[w]);
            }
            else{
            printf(" %d",ans[w]);
            }
        }
    return 0;
}
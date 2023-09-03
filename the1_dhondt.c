#include <stdio.h>

int main(void) {

    int N,M,num_votes[26],i,j,k,l,m,n,o,p,num_seats[26];
    float quotient[26];
    char party_names[26];

    /*take in values of N and M*/
    scanf("%i %i\n",&N,&M);

    /*take in the votes of parties and put it in an array*/
    for (i=0;i<N;i++) {
        int vote_party;
        scanf("%i ",&vote_party);
        num_votes[i]=vote_party;
    }

    /*create array of party names*/
    for (n=0;n<26;n++) {
        party_names[n]='A'+n;
    }

   /*initialize the seat array with all zeros*/
   for (m=0;m<N;m++) {
        num_seats[m]=0;
   }
    
    for (l=0;l<M;l++) {
        float max=0;
        int index_max=0;
        for (k=0;k<N;k++) {
            quotient[k]=((float)num_votes[k])/(num_seats[k]+1);
        }
        for (j=0;j<N;j++) {
                if (quotient[j]>max) {
                    max=quotient[j];
                    index_max=j;
                }
                else if (quotient[j]==max) {
                    if (num_votes[j]>num_votes[index_max]) {
                        max=quotient[j];
                        index_max=j;
                    } 
                    else if (num_votes[j]<num_votes[index_max]){
                        ;
                    }
                }
            }
        num_seats[index_max]+=1;
    }
    
    for (n=0;n<N;n++) {
        int temp_num=0,temp_name=' ';
        for (o=n+1;o<N;o++) {
            if (num_seats[n]<num_seats[o]) {
                temp_num = num_seats[n];
                num_seats[n] = num_seats[o];
                num_seats [o] = temp_num;

                temp_name = party_names[n];
                party_names[n] = party_names[o];
                party_names[o] = temp_name;
            }
            else if (num_seats[n]==num_seats[o]) {
                if (party_names[n]>party_names[o]) {
                    temp_num = num_seats[n];
                num_seats[n] = num_seats[o];
                num_seats [o] = temp_num;

                temp_name = party_names[n];
                party_names[n] = party_names[o];
                party_names[o] = temp_name;
                }
            }
        }
    }
    

    for (p=0;p<N;p++) {
        if (num_seats[p]!=0) {
        printf("%c: %i\n",party_names[p],num_seats[p]);
        }
    }
    
    return 0;
}  

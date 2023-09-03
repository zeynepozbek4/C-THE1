#include <stdio.h>

double calculate_pressure_on_block(int row, int column, double block_weight) {
    if (column==0) {
        if (row==1) {
            return block_weight/2;
        }
        return block_weight/2 + (0.15)*calculate_pressure_on_block(row-1,column,block_weight);
    }
    
    else if (column==row) {
        if (row==1) {
            return block_weight/2;
        }
    return block_weight/2 + (0.15)*calculate_pressure_on_block(row-1,column-1,block_weight);
    }

    else {
        if (row==1) {
            return block_weight/2;
        }
        return block_weight + (0.15)*calculate_pressure_on_block(row-1,column,block_weight) + (0.15)*calculate_pressure_on_block(row-1,column-1,block_weight);
    }
}

void printer(int row, int column, double block_weight) {
    if (row==0&&column==0) {
        printf("(0,0) 0.00000000\n");
        return;
    }
    if (column == 0&&row!=0) {
        printer(row-1,row-1,block_weight);
        printf("(%i,%i) %.8f\n",row,column,calculate_pressure_on_block(row,column,block_weight));
    }
    else {
        printer(row,column-1,block_weight);
        printf("(%i,%i) %.8f\n",row,column,calculate_pressure_on_block(row,column,block_weight));
    }
}

int main() {
    int layer; 
    double block_weight;
    scanf("%i %lf",&layer,&block_weight);
    printer(layer-1,layer-1,block_weight);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "node.h"
#include "queue_functions.h"

#define ROWS    10
#define COLS    10

void print_grid(int * ptr, int num_rows, int num_cols);
int find_shortest_path(int * my_grid, int num_rows, int num_cols, int src_x, int src_y, int dst_x, int dst_y);

int main()
{
    ///****************** This section genarates the grid containing 1s and 0s *********************//
    srand((unsigned int)time(NULL));    /// initializing the psudorandom generator with time as seed value

    int my_grid[ROWS][COLS];

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            my_grid[i][j] = ((rand() % 10) > 7);    /// Initialize the grid with randomly placed 0 and 1
            printf("%d\t", my_grid[i][j]);
        }
        printf("\n");
    }

    ///**********************************************************************************************/

    ///****************** Variable Declaration here ***************************/
    int num_rows = ROWS;
    int num_cols = COLS;

    int src_x = 0;  /// Specifying the start node coordinates in the grid
    int src_y = 0;

    int dst_x = 3;  /// Specifying the end node coordinates in the grid
    int dst_y = 2;

    int path_cost;  /// This will hold the cost of moving from start to end node

    ///**********************************************************************************************/
    path_cost = find_shortest_path(&my_grid[0][0], num_rows, num_cols, src_x, src_y, dst_x, dst_y);

    printf("\n\nThe shortest path between Source and Destination costs: %d\n\n", path_cost);

    return 0;
}

int find_shortest_path(int * my_grid, int num_rows, int num_cols, int src_x, int src_y, int dst_x, int dst_y)
{
    if((src_x >= num_cols)||(src_y >= num_rows)||(dst_x >= num_cols)||(dst_y >= num_rows))
        return(-1);     /// Source or Destination cell is out of bounds

    int dx[4] = {-1, 1, 0, 0};  /// Vectors for directions
    int dy[4] = {0, 0, 1, -1};

    int visited[num_rows][num_cols];   /// To keep track of which cells have been visited.
    memset(visited,0,num_rows * num_cols * sizeof(int));     /// Initiallize with zeros. 1 means visited.

    int dist[num_rows][num_cols];   /// To keep track of distance between cells
    memset(dist,10000,num_rows * num_cols * sizeof(int));     /// Initiallize with a very large integer.

    struct node * qfront = NULL;   /// This is the front of the queue
    struct node * qrear = NULL;   /// This is the rear of the queue

    struct element current_visiting;
    struct element temp;

    int visiting_x = src_x;
    int visiting_y = src_y;

    temp.x_index = src_x;
    temp.y_index = src_y;


    q_insert(&qrear, &qfront, temp);

    visited[src_x][src_y] = 1;   /// Mark the cell as visited
    dist[src_x][src_y] = 0;      /// Cost of visiting the source node is 0

    while(! q_isEmpty(&qfront))    /// while the queue is not empty
    {
        current_visiting = q_delete(&qfront);   /// Step 1: remove the node at the front

        visiting_x = current_visiting.x_index;
        visiting_y = current_visiting.y_index;

        if((visiting_x == dst_x) && (visiting_y == dst_y))    /// found the destination
            break;
        else        /// Add the neighbours with cost added into the que
        {

            for(int i=0; i<4; i++)      /// Visiting the 4 possible neighbours.
            {
                int nx = visiting_x + dx[i];
                int ny = visiting_y + dy[i];

                if((nx < 0) || (ny < 0))
                    continue;
                if((nx >= num_cols) || (ny >= num_rows))
                    continue;

                temp.x_index = nx;
                temp.y_index = ny;

                if(visited[nx][ny] == 0) /// if the cell has not been visited yet.
                {
                    dist[nx][ny] = dist[visiting_x][visiting_y] + 1;
                    q_insert(&qrear, &qfront, temp);
                    visited[nx][ny] = 1;    /// mark it as visited
                }

            }

        }

            //print_grid(&visited[0][0], num_rows, num_cols);
            //printf("\n\n");
        }
        return(dist[visiting_x][visiting_y]);
    }

void print_grid(int * ptr, int num_rows, int num_cols)
{

    for(int i=0; i<num_rows; i++)
    {
        for(int j=0; j<num_cols; j++)
            printf("%d\t", *(ptr + ((i * num_cols)+j)));
        printf("\n");
    }
}


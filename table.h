#ifndef TABLE_H
#define TABLE_H

#define MAX_NAME 15
#define MAX_COLS 15
#define MAX_ROWS 100

typedef enum
{
    TYPE_INT,
    TYPE_TEXT
}ColumnType;

typedef struct
{
    char name[MAX_NAME];
    ColumnType type;
}Column;

typedef struct
{
    int int_value[MAX_COLS];
    char text_values[MAX_COLS][MAX_NAME];
}Row;

//tabel struct
typedef struct
{
    char name[MAX_NAME];        //table has a name
    
    int col_count;
    Column column[MAX_COLS];    //table contains multiple cols
    
    int row_count;
    Row row;                    //table contains multiple rows
}Table;

#endif
// Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.

// Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности.

// Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.

void swap_min( int *m[], unsigned int rows, unsigned int cols )
{
    unsigned int min_row = 0, min_col = 0;

    for ( unsigned int i = 0; i != rows ; i++ )
    {
        for ( unsigned int j = 0; j != cols ; j++ )
        {
            if ( m[i][j] < m[min_row][min_col] )
            {
                min_row = i;
                min_col = j;
            }
        }
    }

    if ( min_row != 0 )
    {
        int *tmp = m[0];
        m[0] = m[min_row];
        m[min_row] = tmp;
    }
}

// int main()
// {
//     unsigned int rows = 4;
//     unsigned int cols = 5;

//     int **m = new int *[rows];

//     for ( unsigned int i = 0; i < rows; i++ )
//     {
//         m[i] = new int[cols];
//     }

//     std::srand( ( unsigned int )std::time( nullptr ) );

//     for ( unsigned int i = 0; i < rows; i++ )
//     {
//         for ( unsigned int j = 0; j < cols; j++ )
//         {
//             m[i][j] = std::rand() % ( rows * cols );
//         }
//     }

//     for ( unsigned int i = 0; i < rows; i++ )
//     {
//         for ( unsigned int j = 0; j < cols; j++ )
//         {
//             std::cout << std::setw( 2 ) << m[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }

//     std::cout << std::endl;

//     swap_min( m, rows, cols );

//     for ( unsigned int i = 0; i < rows; i++ )
//     {
//         for ( unsigned int j = 0; j < cols; j++ )
//         {
//             std::cout << std::setw( 2 ) << m[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }

//     std::cout << std::endl;

//     for ( unsigned int i = 0; i < rows; i++ )
//     {
//         delete [] m[i];
//     }

//     delete [] m;
// }
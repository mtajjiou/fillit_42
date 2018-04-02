/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajjiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:51:23 by mtajjiou          #+#    #+#             */
/*   Updated: 2018/04/02 15:52:17 by mtajjiou         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 21

//TODO FIX MEMORY MANAGMENT

char **read_minos(char const *fileName) {
    int fd;
    char *buffer;
    ssize_t count;
    char **arr;
    int i;

    if (!(arr = (char **) ft_strnew(sizeof(char **) * 20)))
        return (NULL);
    buffer = ft_strnew(BUFFER_SIZE);
    i = 0;
    fd = open(fileName, O_RDONLY);
    while ((count = read(fd, buffer, BUFFER_SIZE)) >= 19) { 
        arr[i++] = ft_strndup(buffer, count);
    }
    i = i + 1;
    arr[i] = NULL;
    return arr;
}

char *get_shapes(char *arr1) {
    char *res;
    char *arr;
    int i;

    i = 0;
    arr = ft_strtrim(arr1);
    if(!(res = (char *) malloc(21)))
        return (ft_strdup("err"));
    if (ft_strstr(arr, "####"))
        res = ft_strdup("####\n....\n....\n....\n");
    else if (ft_strstr(arr, "#...#...#...#"))
        res = ft_strdup("#...\n#...\n#...\n#...\n");
    else if (ft_strstr(arr, "#...###"))
        res = ft_strdup("#...\n###.\n....\n....\n");
    else if (ft_strstr(arr, "##..#...#"))
        res = ft_strdup("##..\n#...\n#...\n....\n");
    else if (ft_strstr(arr, "###...#"))
        res = ft_strdup("###.\n..#.\n....\n....\n");
    else if (ft_strstr(arr, "#...#..##"))
        res = ft_strdup(".#..\n.#..\n##..\n....\n");
    else if (ft_strstr(arr, "#.###"))
        res = ft_strdup("..#.\n###.\n....\n....\n");
    else if (ft_strstr(arr, "#...#...##"))
        res = ft_strdup("#...\n#...\n##..\n....\n");
    else if (ft_strstr(arr, "###.#"))
        res = ft_strdup("###.\n#...\n....\n....\n");
    else if (ft_strstr(arr, "##...#...#"))
        res = ft_strdup("###.\n.#..\n.#..\n....\n");
    else if (ft_strstr(arr, "##..##"))
        res = ft_strdup("##..\n##..\n....\n....\n");
    else if (ft_strstr(arr, "##.##"))
        res = ft_strdup("##..\n.##.\n....\n....\n");
    else if (ft_strstr(arr, "#...##...#"))
        res = ft_strdup("#...\n##..\n.#..\n....\n");
    else if (ft_strstr(arr, "#..###"))
        res = ft_strdup("#..#\n##..\n....\n....\n");
    else if (ft_strstr(arr, "#...##..#"))
        res = ft_strdup("#...\n##..\n#...\n....\n");
    else if (ft_strstr(arr, "###..#"))
        res = ft_strdup("###.\n.#..\n....\n....\n");
    else if (ft_strstr(arr, "#..##...#"))
        res = ft_strdup("#..#\n#...\n#...\n....\n");
    else if (ft_strstr(arr, "##...##"))
        res = ft_strdup("##..\n.##.\n....\n....\n");
    else if (ft_strstr(arr, "#..##..#"))
        res = ft_strdup("#..#\n#..#\n....\n....\n");
    else
        res = ft_strdup("err");
    return (res);
}

int get_arr_size(char **str) {
    int i;

    i = 0;
    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

int get_board_size(char **arr) {
    return (get_arr_size(arr) + 1);
}

int check_invalid_board_spacing(char **arr) {
    int i;

    i = 0;
    while (arr[i] != NULL) {

        if(i != 0)
        {
            if (arr[i - 1][20] == '.' || arr[i][20] == '#') {
                return (1);
            }
        }

        if (arr[i][20] == '.' || arr[i][20] == '#') {
            return (1);
        }

        if (arr[i][19] == '\n' && (arr[i][20] != '.' || arr[i][20] != '#')) {
            return (0);
        }
        if (arr[i][19] == '\n' && arr[i][20] == '\0') {
            return (0);
        }

        i++;
    }

    if (arr[get_arr_size(arr)][20] != '\0' && arr[get_arr_size(arr)][20] != '\0') {
        return (1);
    }
    return (1);
}

int check_invalid_board(char **arr) {
    int size;
    int i;
    int j;

    j = 0;
    i = 0;
    size = get_arr_size(arr);
    while (i <= size) {
        i++;
        while (j < 4)
        {
            j++;
            if (arr[i][j * 4] == '\n') {
                return (0);
            } else {
                error_msg();
                return (1);
            }
        }
    }
    return (1);
}

char **final_array(char **arr, int *res) {
    int i;
    int j;
    char **ret;
    if(!(ret = (char **) malloc(sizeof(char **) * (get_board_size(arr)))))
        return (NULL);

    i = 0;
    j = 0;
    while (arr[i] != NULL) {
        if (ft_strcmp(get_shapes(ft_remove_char(arr[0], '\n')), "err"))
            *res = 1;
        ret[j++] = get_shapes(ft_remove_char(arr[i], '\n'));
        i++;
    }
    j = j + 1;
    ret[j] = NULL;
    return (ret);
}

char **get_valid_shapes(char const *argv) {
    char **boards;
    char **shapes;
    int res;

    res = 0;
    boards = read_minos(argv);
    if(!(shapes = (char **) malloc(sizeof(char **) * (get_board_size(boards)))))
        return (NULL);

    if (check_invalid_board_spacing(boards) == 0 && check_invalid_board(boards) == 0)
        shapes = final_array(boards, &res);
    else
        error_msg();

    if (res == 0)
        error_msg();
    return (shapes);
}

char **get_valid_mino(char const *argv) {
    char **board;
    char **shapes;
    int i;
    int size;

    i = 0;
    shapes = get_valid_shapes(argv);
    size = get_board_size(shapes);
    if(!(board = (char **) malloc(sizeof(char **) * ((size + 1)))))
        return (NULL);
    while (i < size) {
        board[i] = shapes[i];
        i++;
    }

    return (board);
}

int main(int argc, char const *argv[]) {
    if (argc == 0)
        usage_msg();
    char **shapes = get_valid_mino((char *) argv[1]);
    printf("%s\n", shapes[0]);
    return 0;
}

#ifndef LAB7_MATRIX_GEN_H
#define LAB7_MATRIX_GEN_H

#define ARG_FAIL -1

#define BASE_10 10
#define IS_VALID_INT(arg_pos, valid) (((valid == argv[arg_pos]) || (*valid != '\0')) == 0)


int validate_args(int argc, char ** argv);
void generate_matrix(int size);

#endif //LAB7_MATRIX_GEN_H

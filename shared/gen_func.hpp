#pragma once

#include <algorithm>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <zlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <gsl/gsl_rng.h>

const uint64_t N_GENO = 3;
const double INF = 1e15;
const double EPSILON = 1e-5;
const uint64_t BUFF_LEN = 100000;
const uint64_t ITER_MAX = 100;

// General definitions
#define abs(x)   ((x) >= 0 ? (x) : -(x))
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define bit_test(a,b)   ((a) >> (b) & 1)
#define bit_clear(a,b)  ((a) & ~((uinteger)1 << (b)))
#define bit_set(a,b)    ((a) |  ((uinteger)1 << (b)))

// PATH bitwise operators
#define path_pos_get(seq, pos)  ( seq[pos/8]  & (1 << pos%8) )
#define path_pos_set0(seq, pos) ( seq[pos/8] &= ~(1 << pos%8) )
#define path_pos_set1(seq, pos) ( seq[pos/8] |= (1 << pos%8) )

// Function prototypes
void warn(const char*, const char*);
void error(const char*, const char*);
void handler(int);
void catch_SIG();
double check_interv(double, bool);
int array_max_pos(double*, int);
int array_min_pos(double*, int);
double*** transp_matrix(double***, uint64_t, uint64_t);
double draw_rnd(gsl_rng*, uint64_t, uint64_t);
void conv_space(double*, int, double (*func)(double));
double logsum(double*, uint64_t);
double logsum(double, double);
double logsum(double, double, double);
double logsum(double, double, double, double);
void chomp(char*);
gzFile open_gzfile(const char*, const char*, uint64_t = 10000);
uint64_t read_file(const char*, char***, uint64_t = BUFF_LEN);
uint64_t read_file(const char*, double***, int, uint64_t = BUFF_LEN);

uint64_t split(char*, const char*, int**);
uint64_t split(char*, const char*, float**);
uint64_t split(char*, const char*, double**);
uint64_t split(char*, const char*, char***);
char *join(unsigned short int*, uint64_t, const char*);
char *join(uint64_t*, uint64_t, const char*);
char *join(double*, uint64_t, const char*);
char *join(char*, uint64_t, const char*);

unsigned short int *init_ptr(uint64_t, unsigned short int);
unsigned short int **init_ptr(uint64_t, uint64_t, unsigned short int);
int *init_ptr(uint64_t, int);
uint64_t *init_ptr(uint64_t, uint64_t);
uint64_t **init_ptr(uint64_t, uint64_t, uint64_t);
float *init_ptr(uint64_t, float);
double *init_ptr(uint64_t, double);
double **init_ptr(uint64_t, uint64_t, double);
double ***init_ptr(uint64_t, uint64_t, uint64_t, double);
double ****init_ptr(uint64_t, uint64_t, uint64_t, uint64_t, double);
char *strdcat(char*, const char*);
char *init_ptr(uint64_t, const char*);
char **init_ptr(uint64_t, uint64_t, const char*);

void free_ptr(void*);
void free_ptr(void**, uint64_t);
void free_ptr(void***, uint64_t, uint64_t);
void free_ptr(void****, uint64_t, uint64_t, uint64_t);

void cpy(void*, void*, uint64_t, uint64_t);
void cpy(void*, void*, uint64_t, uint64_t, uint64_t);
void cpy(void*, void*, uint64_t, uint64_t, uint64_t, uint64_t);
void cpy(void*, void*, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

bool miss_data(double*);
void call_geno(double*, int, bool = true, double = 0, double = 0, int = 0);
void post_prob(double*, double*, double*, uint64_t);
void calc_HWE(double*, double, double);
double est_maf(uint64_t, double**, double);
double est_maf(uint64_t, double**, double*);

void bcf_pair_LD (double*, double**, double**, double, double, uint64_t, bool = true);
int haplo_freq(double*, double**, double**, double, double, uint64_t, bool = true);
int pair_freq_iter(double*, double**, double**, uint64_t);
int pair_freq_iter_log(double*, double**, double**, uint64_t);

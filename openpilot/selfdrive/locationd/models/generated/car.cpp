#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_516126113711711650) {
   out_516126113711711650[0] = delta_x[0] + nom_x[0];
   out_516126113711711650[1] = delta_x[1] + nom_x[1];
   out_516126113711711650[2] = delta_x[2] + nom_x[2];
   out_516126113711711650[3] = delta_x[3] + nom_x[3];
   out_516126113711711650[4] = delta_x[4] + nom_x[4];
   out_516126113711711650[5] = delta_x[5] + nom_x[5];
   out_516126113711711650[6] = delta_x[6] + nom_x[6];
   out_516126113711711650[7] = delta_x[7] + nom_x[7];
   out_516126113711711650[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6452492328306863760) {
   out_6452492328306863760[0] = -nom_x[0] + true_x[0];
   out_6452492328306863760[1] = -nom_x[1] + true_x[1];
   out_6452492328306863760[2] = -nom_x[2] + true_x[2];
   out_6452492328306863760[3] = -nom_x[3] + true_x[3];
   out_6452492328306863760[4] = -nom_x[4] + true_x[4];
   out_6452492328306863760[5] = -nom_x[5] + true_x[5];
   out_6452492328306863760[6] = -nom_x[6] + true_x[6];
   out_6452492328306863760[7] = -nom_x[7] + true_x[7];
   out_6452492328306863760[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_561367379597116933) {
   out_561367379597116933[0] = 1.0;
   out_561367379597116933[1] = 0.0;
   out_561367379597116933[2] = 0.0;
   out_561367379597116933[3] = 0.0;
   out_561367379597116933[4] = 0.0;
   out_561367379597116933[5] = 0.0;
   out_561367379597116933[6] = 0.0;
   out_561367379597116933[7] = 0.0;
   out_561367379597116933[8] = 0.0;
   out_561367379597116933[9] = 0.0;
   out_561367379597116933[10] = 1.0;
   out_561367379597116933[11] = 0.0;
   out_561367379597116933[12] = 0.0;
   out_561367379597116933[13] = 0.0;
   out_561367379597116933[14] = 0.0;
   out_561367379597116933[15] = 0.0;
   out_561367379597116933[16] = 0.0;
   out_561367379597116933[17] = 0.0;
   out_561367379597116933[18] = 0.0;
   out_561367379597116933[19] = 0.0;
   out_561367379597116933[20] = 1.0;
   out_561367379597116933[21] = 0.0;
   out_561367379597116933[22] = 0.0;
   out_561367379597116933[23] = 0.0;
   out_561367379597116933[24] = 0.0;
   out_561367379597116933[25] = 0.0;
   out_561367379597116933[26] = 0.0;
   out_561367379597116933[27] = 0.0;
   out_561367379597116933[28] = 0.0;
   out_561367379597116933[29] = 0.0;
   out_561367379597116933[30] = 1.0;
   out_561367379597116933[31] = 0.0;
   out_561367379597116933[32] = 0.0;
   out_561367379597116933[33] = 0.0;
   out_561367379597116933[34] = 0.0;
   out_561367379597116933[35] = 0.0;
   out_561367379597116933[36] = 0.0;
   out_561367379597116933[37] = 0.0;
   out_561367379597116933[38] = 0.0;
   out_561367379597116933[39] = 0.0;
   out_561367379597116933[40] = 1.0;
   out_561367379597116933[41] = 0.0;
   out_561367379597116933[42] = 0.0;
   out_561367379597116933[43] = 0.0;
   out_561367379597116933[44] = 0.0;
   out_561367379597116933[45] = 0.0;
   out_561367379597116933[46] = 0.0;
   out_561367379597116933[47] = 0.0;
   out_561367379597116933[48] = 0.0;
   out_561367379597116933[49] = 0.0;
   out_561367379597116933[50] = 1.0;
   out_561367379597116933[51] = 0.0;
   out_561367379597116933[52] = 0.0;
   out_561367379597116933[53] = 0.0;
   out_561367379597116933[54] = 0.0;
   out_561367379597116933[55] = 0.0;
   out_561367379597116933[56] = 0.0;
   out_561367379597116933[57] = 0.0;
   out_561367379597116933[58] = 0.0;
   out_561367379597116933[59] = 0.0;
   out_561367379597116933[60] = 1.0;
   out_561367379597116933[61] = 0.0;
   out_561367379597116933[62] = 0.0;
   out_561367379597116933[63] = 0.0;
   out_561367379597116933[64] = 0.0;
   out_561367379597116933[65] = 0.0;
   out_561367379597116933[66] = 0.0;
   out_561367379597116933[67] = 0.0;
   out_561367379597116933[68] = 0.0;
   out_561367379597116933[69] = 0.0;
   out_561367379597116933[70] = 1.0;
   out_561367379597116933[71] = 0.0;
   out_561367379597116933[72] = 0.0;
   out_561367379597116933[73] = 0.0;
   out_561367379597116933[74] = 0.0;
   out_561367379597116933[75] = 0.0;
   out_561367379597116933[76] = 0.0;
   out_561367379597116933[77] = 0.0;
   out_561367379597116933[78] = 0.0;
   out_561367379597116933[79] = 0.0;
   out_561367379597116933[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_777691313942151638) {
   out_777691313942151638[0] = state[0];
   out_777691313942151638[1] = state[1];
   out_777691313942151638[2] = state[2];
   out_777691313942151638[3] = state[3];
   out_777691313942151638[4] = state[4];
   out_777691313942151638[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_777691313942151638[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_777691313942151638[7] = state[7];
   out_777691313942151638[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7802811861687659975) {
   out_7802811861687659975[0] = 1;
   out_7802811861687659975[1] = 0;
   out_7802811861687659975[2] = 0;
   out_7802811861687659975[3] = 0;
   out_7802811861687659975[4] = 0;
   out_7802811861687659975[5] = 0;
   out_7802811861687659975[6] = 0;
   out_7802811861687659975[7] = 0;
   out_7802811861687659975[8] = 0;
   out_7802811861687659975[9] = 0;
   out_7802811861687659975[10] = 1;
   out_7802811861687659975[11] = 0;
   out_7802811861687659975[12] = 0;
   out_7802811861687659975[13] = 0;
   out_7802811861687659975[14] = 0;
   out_7802811861687659975[15] = 0;
   out_7802811861687659975[16] = 0;
   out_7802811861687659975[17] = 0;
   out_7802811861687659975[18] = 0;
   out_7802811861687659975[19] = 0;
   out_7802811861687659975[20] = 1;
   out_7802811861687659975[21] = 0;
   out_7802811861687659975[22] = 0;
   out_7802811861687659975[23] = 0;
   out_7802811861687659975[24] = 0;
   out_7802811861687659975[25] = 0;
   out_7802811861687659975[26] = 0;
   out_7802811861687659975[27] = 0;
   out_7802811861687659975[28] = 0;
   out_7802811861687659975[29] = 0;
   out_7802811861687659975[30] = 1;
   out_7802811861687659975[31] = 0;
   out_7802811861687659975[32] = 0;
   out_7802811861687659975[33] = 0;
   out_7802811861687659975[34] = 0;
   out_7802811861687659975[35] = 0;
   out_7802811861687659975[36] = 0;
   out_7802811861687659975[37] = 0;
   out_7802811861687659975[38] = 0;
   out_7802811861687659975[39] = 0;
   out_7802811861687659975[40] = 1;
   out_7802811861687659975[41] = 0;
   out_7802811861687659975[42] = 0;
   out_7802811861687659975[43] = 0;
   out_7802811861687659975[44] = 0;
   out_7802811861687659975[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7802811861687659975[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7802811861687659975[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7802811861687659975[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7802811861687659975[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7802811861687659975[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7802811861687659975[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7802811861687659975[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7802811861687659975[53] = -9.8100000000000005*dt;
   out_7802811861687659975[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7802811861687659975[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7802811861687659975[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7802811861687659975[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7802811861687659975[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7802811861687659975[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7802811861687659975[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7802811861687659975[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7802811861687659975[62] = 0;
   out_7802811861687659975[63] = 0;
   out_7802811861687659975[64] = 0;
   out_7802811861687659975[65] = 0;
   out_7802811861687659975[66] = 0;
   out_7802811861687659975[67] = 0;
   out_7802811861687659975[68] = 0;
   out_7802811861687659975[69] = 0;
   out_7802811861687659975[70] = 1;
   out_7802811861687659975[71] = 0;
   out_7802811861687659975[72] = 0;
   out_7802811861687659975[73] = 0;
   out_7802811861687659975[74] = 0;
   out_7802811861687659975[75] = 0;
   out_7802811861687659975[76] = 0;
   out_7802811861687659975[77] = 0;
   out_7802811861687659975[78] = 0;
   out_7802811861687659975[79] = 0;
   out_7802811861687659975[80] = 1;
}
void h_25(double *state, double *unused, double *out_2649276739528629921) {
   out_2649276739528629921[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8631820846315120304) {
   out_8631820846315120304[0] = 0;
   out_8631820846315120304[1] = 0;
   out_8631820846315120304[2] = 0;
   out_8631820846315120304[3] = 0;
   out_8631820846315120304[4] = 0;
   out_8631820846315120304[5] = 0;
   out_8631820846315120304[6] = 1;
   out_8631820846315120304[7] = 0;
   out_8631820846315120304[8] = 0;
}
void h_24(double *state, double *unused, double *out_4474589522987235323) {
   out_4474589522987235323[0] = state[4];
   out_4474589522987235323[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7642273628388931746) {
   out_7642273628388931746[0] = 0;
   out_7642273628388931746[1] = 0;
   out_7642273628388931746[2] = 0;
   out_7642273628388931746[3] = 0;
   out_7642273628388931746[4] = 1;
   out_7642273628388931746[5] = 0;
   out_7642273628388931746[6] = 0;
   out_7642273628388931746[7] = 0;
   out_7642273628388931746[8] = 0;
   out_7642273628388931746[9] = 0;
   out_7642273628388931746[10] = 0;
   out_7642273628388931746[11] = 0;
   out_7642273628388931746[12] = 0;
   out_7642273628388931746[13] = 0;
   out_7642273628388931746[14] = 1;
   out_7642273628388931746[15] = 0;
   out_7642273628388931746[16] = 0;
   out_7642273628388931746[17] = 0;
}
void h_30(double *state, double *unused, double *out_1591893975104609062) {
   out_1591893975104609062[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1715130504823503549) {
   out_1715130504823503549[0] = 0;
   out_1715130504823503549[1] = 0;
   out_1715130504823503549[2] = 0;
   out_1715130504823503549[3] = 0;
   out_1715130504823503549[4] = 1;
   out_1715130504823503549[5] = 0;
   out_1715130504823503549[6] = 0;
   out_1715130504823503549[7] = 0;
   out_1715130504823503549[8] = 0;
}
void h_26(double *state, double *unused, double *out_2678620623461073389) {
   out_2678620623461073389[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6073419908520375088) {
   out_6073419908520375088[0] = 0;
   out_6073419908520375088[1] = 0;
   out_6073419908520375088[2] = 0;
   out_6073419908520375088[3] = 0;
   out_6073419908520375088[4] = 0;
   out_6073419908520375088[5] = 0;
   out_6073419908520375088[6] = 0;
   out_6073419908520375088[7] = 1;
   out_6073419908520375088[8] = 0;
}
void h_27(double *state, double *unused, double *out_5686062790972962606) {
   out_5686062790972962606[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3889893816623928460) {
   out_3889893816623928460[0] = 0;
   out_3889893816623928460[1] = 0;
   out_3889893816623928460[2] = 0;
   out_3889893816623928460[3] = 1;
   out_3889893816623928460[4] = 0;
   out_3889893816623928460[5] = 0;
   out_3889893816623928460[6] = 0;
   out_3889893816623928460[7] = 0;
   out_3889893816623928460[8] = 0;
}
void h_29(double *state, double *unused, double *out_2195209859781086579) {
   out_2195209859781086579[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5603256543493479493) {
   out_5603256543493479493[0] = 0;
   out_5603256543493479493[1] = 1;
   out_5603256543493479493[2] = 0;
   out_5603256543493479493[3] = 0;
   out_5603256543493479493[4] = 0;
   out_5603256543493479493[5] = 0;
   out_5603256543493479493[6] = 0;
   out_5603256543493479493[7] = 0;
   out_5603256543493479493[8] = 0;
}
void h_28(double *state, double *unused, double *out_6629572643874625041) {
   out_6629572643874625041[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7761088513146541549) {
   out_7761088513146541549[0] = 1;
   out_7761088513146541549[1] = 0;
   out_7761088513146541549[2] = 0;
   out_7761088513146541549[3] = 0;
   out_7761088513146541549[4] = 0;
   out_7761088513146541549[5] = 0;
   out_7761088513146541549[6] = 0;
   out_7761088513146541549[7] = 0;
   out_7761088513146541549[8] = 0;
}
void h_31(double *state, double *unused, double *out_4121558486821721015) {
   out_4121558486821721015[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8601174884438159876) {
   out_8601174884438159876[0] = 0;
   out_8601174884438159876[1] = 0;
   out_8601174884438159876[2] = 0;
   out_8601174884438159876[3] = 0;
   out_8601174884438159876[4] = 0;
   out_8601174884438159876[5] = 0;
   out_8601174884438159876[6] = 0;
   out_8601174884438159876[7] = 0;
   out_8601174884438159876[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_516126113711711650) {
  err_fun(nom_x, delta_x, out_516126113711711650);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6452492328306863760) {
  inv_err_fun(nom_x, true_x, out_6452492328306863760);
}
void car_H_mod_fun(double *state, double *out_561367379597116933) {
  H_mod_fun(state, out_561367379597116933);
}
void car_f_fun(double *state, double dt, double *out_777691313942151638) {
  f_fun(state,  dt, out_777691313942151638);
}
void car_F_fun(double *state, double dt, double *out_7802811861687659975) {
  F_fun(state,  dt, out_7802811861687659975);
}
void car_h_25(double *state, double *unused, double *out_2649276739528629921) {
  h_25(state, unused, out_2649276739528629921);
}
void car_H_25(double *state, double *unused, double *out_8631820846315120304) {
  H_25(state, unused, out_8631820846315120304);
}
void car_h_24(double *state, double *unused, double *out_4474589522987235323) {
  h_24(state, unused, out_4474589522987235323);
}
void car_H_24(double *state, double *unused, double *out_7642273628388931746) {
  H_24(state, unused, out_7642273628388931746);
}
void car_h_30(double *state, double *unused, double *out_1591893975104609062) {
  h_30(state, unused, out_1591893975104609062);
}
void car_H_30(double *state, double *unused, double *out_1715130504823503549) {
  H_30(state, unused, out_1715130504823503549);
}
void car_h_26(double *state, double *unused, double *out_2678620623461073389) {
  h_26(state, unused, out_2678620623461073389);
}
void car_H_26(double *state, double *unused, double *out_6073419908520375088) {
  H_26(state, unused, out_6073419908520375088);
}
void car_h_27(double *state, double *unused, double *out_5686062790972962606) {
  h_27(state, unused, out_5686062790972962606);
}
void car_H_27(double *state, double *unused, double *out_3889893816623928460) {
  H_27(state, unused, out_3889893816623928460);
}
void car_h_29(double *state, double *unused, double *out_2195209859781086579) {
  h_29(state, unused, out_2195209859781086579);
}
void car_H_29(double *state, double *unused, double *out_5603256543493479493) {
  H_29(state, unused, out_5603256543493479493);
}
void car_h_28(double *state, double *unused, double *out_6629572643874625041) {
  h_28(state, unused, out_6629572643874625041);
}
void car_H_28(double *state, double *unused, double *out_7761088513146541549) {
  H_28(state, unused, out_7761088513146541549);
}
void car_h_31(double *state, double *unused, double *out_4121558486821721015) {
  h_31(state, unused, out_4121558486821721015);
}
void car_H_31(double *state, double *unused, double *out_8601174884438159876) {
  H_31(state, unused, out_8601174884438159876);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)

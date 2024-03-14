//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
using namespace std;
void mm1(
  hls::stream< float > &v0 /* v0[180][210] */,
  hls::stream< float > &v1 /* v1[210][190] */,
  hls::stream< float > &v2 /* v2[180][190] */
) {	// L2
  #pragma HLS dataflow
  #pragma HLS stream variable=v0 depth=4
  #pragma HLS stream variable=v1 depth=4
  #pragma HLS stream variable=v2 depth=34200
  l_mm1_i0: for (int i0 = 0; i0 < 180; i0++) {	// L3
  #pragma HLS dataflow
    float v4[190];	// L4
    l_j0_init: for (int j0_init = 0; j0_init < 190; j0_init++) {	// L6
    #pragma HLS pipeline II=1
      v4[j0_init] = 0.000000;	// L7
    }
    l_S_k0_0_k0: for (int k0 = 0; k0 < 210; k0++) {	// L9
    #pragma HLS pipeline II=1
      l_j0: for (int j0 = 0; j0 < 190; j0++) {	// L10
        float v8 = v0.read(); // v0[i0][k0];	// L11
        float v9 = v1.read(); // v1[k0][j0];	// L12
        float v10 = v8 * v9;	// L13
        float v11 = v4[j0];	// L14
        float v12 = v11 + v10;	// L15
        v4[j0] = v12;	// L16
      }
    }
    l_j0_back: for (int j0_back = 0; j0_back < 190; j0_back++) {	// L19
    #pragma HLS pipeline II=1
      float v14 = v4[j0_back];	// L20
      v2.write(v14); // v2[i0][j0_back] = v14;	// L21
    }
  }
}

void mm2(
  hls::stream< float > &v15 /* v15[180][190] */,
  hls::stream< float > &v16 /* v16[190][220] */,
  float v17[180][220]
) {	// L26
  #pragma HLS dataflow
  #pragma HLS stream variable=v15 depth=34200
  #pragma HLS stream variable=v16 depth=4
  l_mm2_i1: for (int i1 = 0; i1 < 180; i1++) {	// L27
  #pragma HLS dataflow
    float v19[220];	// L28
    l_j1_init: for (int j1_init = 0; j1_init < 220; j1_init++) {	// L30
    #pragma HLS pipeline II=1
      v19[j1_init] = 0.000000;	// L31
    }
    l_S_k1_0_k1: for (int k1 = 0; k1 < 190; k1++) {	// L33
    #pragma HLS pipeline II=1
      l_j1: for (int j1 = 0; j1 < 220; j1++) {	// L34
        float v23 = v15.read(); // v15[i1][k1];	// L35
        float v24 = v16.read(); // v16[k1][j1];	// L36
        float v25 = v23 * v24;	// L37
        float v26 = v19[j1];	// L38
        float v27 = v26 + v25;	// L39
        v19[j1] = v27;	// L40
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 220; j1_back++) {	// L43
    #pragma HLS pipeline II=1
      float v29 = v19[j1_back];	// L44
      v17[i1][j1_back] = v29;	// L45
    }
  }
}

void ele_add(
  float v30[180][220],
  hls::stream< float > &v31 /* v31[180][220] */,
  hls::stream< float > &v32 /* v32[180][220] */
) {	// L50
  #pragma HLS stream variable=v31 depth=4
  #pragma HLS stream variable=v32 depth=4
  l_S_i2_j2_0_i2: for (int i2 = 0; i2 < 180; i2++) {	// L51
    l_j2: for (int j2 = 0; j2 < 220; j2++) {	// L52
    #pragma HLS pipeline II=1
      float v35 = v30[i2][j2];	// L53
      float v36 = v35 * 0.500000;	// L55
      float v37 = v31.read(); // v31[i2][j2];	// L56
      float v38 = v37 * 0.100000;	// L58
      float v39 = v36 + v38;	// L59
      v32.write(v39); // v32[i2][j2] = v39;	// L60
    }
  }
}

void kernel_2mm(
  float v40[37800],
  float v41[39900],
  float v42[41800],
  float v43[39600],
  float v44[39600]
) {	// L65
  #pragma HLS dataflow
  hls::stream< float > buf0 /* buf0[180][210] */;	//
  #pragma HLS stream variable=buf0 depth=4
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 180; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 210; buf0_l_1++) {	//
    #pragma HLS pipeline II=1
      float v48 = v40[((buf0_l_0 * 210) + buf0_l_1)];	//
      buf0.write(v48); // buf0[buf0_l_0][buf0_l_1] = v48;	//
    }
  }
  hls::stream< float > buf1 /* buf1[210][190] */;	//
  #pragma HLS stream variable=buf1 depth=4
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 210; buf1_l_0++) {	//
    l_buf1_l_1: for (int buf1_l_1 = 0; buf1_l_1 < 190; buf1_l_1++) {	//
    #pragma HLS pipeline II=1
      float v52 = v41[((buf1_l_0 * 190) + buf1_l_1)];	//
      buf1.write(v52); // buf1[buf1_l_0][buf1_l_1] = v52;	//
    }
  }
  hls::stream< float > buf2 /* buf2[190][220] */;	//
  #pragma HLS stream variable=buf2 depth=4
  l_S_buf2_buf2_l_0: for (int buf2_l_0 = 0; buf2_l_0 < 190; buf2_l_0++) {	//
    l_buf2_l_1: for (int buf2_l_1 = 0; buf2_l_1 < 220; buf2_l_1++) {	//
    #pragma HLS pipeline II=1
      float v56 = v42[((buf2_l_0 * 220) + buf2_l_1)];	//
      buf2.write(v56); // buf2[buf2_l_0][buf2_l_1] = v56;	//
    }
  }
  hls::stream< float > buf3 /* buf3[180][220] */;	//
  #pragma HLS stream variable=buf3 depth=4
  l_S_buf3_buf3_l_0: for (int buf3_l_0 = 0; buf3_l_0 < 180; buf3_l_0++) {	//
    l_buf3_l_1: for (int buf3_l_1 = 0; buf3_l_1 < 220; buf3_l_1++) {	//
    #pragma HLS pipeline II=1
      float v60 = v43[((buf3_l_0 * 220) + buf3_l_1)];	//
      buf3.write(v60); // buf3[buf3_l_0][buf3_l_1] = v60;	//
    }
  }
  hls::stream< float > out_AB /* out_AB[180][190] */;	// L66
  #pragma HLS stream variable=out_AB depth=34200
  float out_ABC[180][220];	// L67
  hls::stream< float > output /* output[180][220] */;	// L68
  #pragma HLS stream variable=output depth=4
  mm1(buf0, buf1, out_AB);	// L69
  mm2(out_AB, buf2, out_ABC);	// L70
  ele_add(out_ABC, buf3, output);	// L71
  l_S_result4_result4_l_0: for (int result4_l_0 = 0; result4_l_0 < 180; result4_l_0++) {	//
    l_result4_l_1: for (int result4_l_1 = 0; result4_l_1 < 220; result4_l_1++) {	//
    #pragma HLS pipeline II=1
      float v66 = output.read(); // output[result4_l_0][result4_l_1];	//
      v44[((result4_l_0 * 220) + result4_l_1)] = v66;	//
    }
  }
}

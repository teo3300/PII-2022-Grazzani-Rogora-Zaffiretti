#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_c "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_c.dat"
#define AUTOTB_TVOUT_c "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_c.dat"
// wrapc file define:
#define AUTOTB_TVIN_clen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_clen.dat"
#define AUTOTB_TVOUT_clen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_clen.dat"
// wrapc file define:
#define AUTOTB_TVIN_m "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_m.dat"
#define AUTOTB_TVOUT_m "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_m.dat"
// wrapc file define:
#define AUTOTB_TVIN_mlen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_mlen.dat"
#define AUTOTB_TVOUT_mlen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_mlen.dat"
// wrapc file define:
#define AUTOTB_TVIN_ad "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_ad.dat"
#define AUTOTB_TVOUT_ad "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_ad.dat"
// wrapc file define:
#define AUTOTB_TVIN_adlen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_adlen.dat"
#define AUTOTB_TVOUT_adlen "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_adlen.dat"
// wrapc file define:
#define AUTOTB_TVIN_nsec "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_nsec.dat"
#define AUTOTB_TVOUT_nsec "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_nsec.dat"
// wrapc file define:
#define AUTOTB_TVIN_npub "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_npub.dat"
#define AUTOTB_TVOUT_npub "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_npub.dat"
// wrapc file define:
#define AUTOTB_TVIN_k "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_k.dat"
#define AUTOTB_TVOUT_k "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_k.dat"
// wrapc file define:
#define AUTOTB_TVIN_st "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvin_st.dat"
#define AUTOTB_TVOUT_st "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_st.dat"
// wrapc file define:
#define AUTOTB_TVOUT_return "../tv/cdatafile/c.crypto_aead_encrypt_h.autotvout_ap_return.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_c "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_c.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_clen "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_clen.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_m "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_m.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_mlen "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_mlen.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_ad "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_ad.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_adlen "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_adlen.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_nsec "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_nsec.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_npub "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_npub.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_k "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_k.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_st "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_st.dat"
#define AUTOTB_TVOUT_PC_return "../tv/rtldatafile/rtl.crypto_aead_encrypt_h.autotvout_ap_return.dat"


inline void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    vp = (p_dat) (p+dbytes);
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};
      

inline const std::string begin_str(int num)
{
  return std::string("[[transaction]] ")
         .append(std::to_string(num))
         .append("\n");
}

inline const std::string end_str()
{
  return std::string("[[/transaction]] \n");
}
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  c_depth = 0;
  clen_depth = 0;
  m_depth = 0;
  mlen_depth = 0;
  ad_depth = 0;
  adlen_depth = 0;
  nsec_depth = 0;
  npub_depth = 0;
  k_depth = 0;
  st_depth = 0;
  return_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{c " << c_depth << "}\n";
  total_list << "{clen " << clen_depth << "}\n";
  total_list << "{m " << m_depth << "}\n";
  total_list << "{mlen " << mlen_depth << "}\n";
  total_list << "{ad " << ad_depth << "}\n";
  total_list << "{adlen " << adlen_depth << "}\n";
  total_list << "{nsec " << nsec_depth << "}\n";
  total_list << "{npub " << npub_depth << "}\n";
  total_list << "{k " << k_depth << "}\n";
  total_list << "{st " << st_depth << "}\n";
  total_list << "{ap_return " << return_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int c_depth;
    int clen_depth;
    int m_depth;
    int mlen_depth;
    int ad_depth;
    int adlen_depth;
    int nsec_depth;
    int npub_depth;
    int k_depth;
    int st_depth;
    int return_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static bool RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool err = false;
  size_t x_found;

  // search and replace 'X' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('X', 0)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  // search and replace 'x' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('x', 2)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  return err;}
extern "C" int crypto_aead_encrypt_h_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, long long, volatile void *, long long, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" int apatb_crypto_aead_encrypt_h_hw(volatile void * __xlx_apatb_param_c, volatile void * __xlx_apatb_param_clen, volatile void * __xlx_apatb_param_m, long long __xlx_apatb_param_mlen, volatile void * __xlx_apatb_param_ad, long long __xlx_apatb_param_adlen, volatile void * __xlx_apatb_param_nsec, volatile void * __xlx_apatb_param_npub, volatile void * __xlx_apatb_param_k, volatile void * __xlx_apatb_param_st) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;

    int AESL_return;
    {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_return);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > return_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "return");
  
            // push token into output port buffer
            if (AESL_token != "") {
              return_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "return" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)&AESL_return)[0*4+0] = return_pc_buffer[0].range(7, 0).to_int64();
((char*)&AESL_return)[0*4+1] = return_pc_buffer[0].range(15, 8).to_int64();
((char*)&AESL_return)[0*4+2] = return_pc_buffer[0].range(23, 16).to_int64();
((char*)&AESL_return)[0*4+3] = return_pc_buffer[0].range(31, 24).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #ifdef USE_BINARY_TV_FILE
{
transaction<8> tr(48);
aesl_fh.read(AUTOTB_TVOUT_PC_c, tr.p, tr.tbytes);
tr.reorder();
tr.send<1>((char*)__xlx_apatb_param_c, 48);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_c);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<8> > c_pc_buffer(48);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "c");
  
            // push token into output port buffer
            if (AESL_token != "") {
              c_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "c" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 48; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_c)[j*1+0] = c_pc_buffer[i].range(7, 0).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_clen);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > clen_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "clen");
  
            // push token into output port buffer
            if (AESL_token != "") {
              clen_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "clen" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {((char*)__xlx_apatb_param_clen)[0*8+0] = clen_pc_buffer[0].range(7, 0).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+1] = clen_pc_buffer[0].range(15, 8).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+2] = clen_pc_buffer[0].range(23, 16).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+3] = clen_pc_buffer[0].range(31, 24).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+4] = clen_pc_buffer[0].range(39, 32).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+5] = clen_pc_buffer[0].range(47, 40).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+6] = clen_pc_buffer[0].range(55, 48).to_int64();
((char*)__xlx_apatb_param_clen)[0*8+7] = clen_pc_buffer[0].range(63, 56).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return  AESL_return;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_c = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_c, 'b');
transaction<8> tr(48);
  __xlx_offset_byte_param_c = 0*1;
  if (__xlx_apatb_param_c) {
tr.import<1>((char*)__xlx_apatb_param_c, 48, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_c, tr.p, tr.tbytes);
}

  tcl_file.set_num(48, &tcl_file.c_depth);
#else
// print c Transactions
{
aesl_fh.write(AUTOTB_TVIN_c, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_c = 0*1;
  if (__xlx_apatb_param_c) {
    for (int j = 0  - 0, e = 48 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_c)[j];
aesl_fh.write(AUTOTB_TVIN_c, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(48, &tcl_file.c_depth);
aesl_fh.write(AUTOTB_TVIN_c, end_str());
}

#endif
// print clen Transactions
{
aesl_fh.write(AUTOTB_TVIN_clen, begin_str(AESL_transaction));
{
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_clen);
aesl_fh.write(AUTOTB_TVIN_clen, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.clen_depth);
aesl_fh.write(AUTOTB_TVIN_clen, end_str());
}

unsigned __xlx_offset_byte_param_m = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_m, 'b');
transaction<8> tr(32);
  __xlx_offset_byte_param_m = 0*1;
  if (__xlx_apatb_param_m) {
tr.import<1>((char*)__xlx_apatb_param_m, 32, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_m, tr.p, tr.tbytes);
}

  tcl_file.set_num(32, &tcl_file.m_depth);
#else
// print m Transactions
{
aesl_fh.write(AUTOTB_TVIN_m, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_m = 0*1;
  if (__xlx_apatb_param_m) {
    for (int j = 0  - 0, e = 32 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_m)[j];
aesl_fh.write(AUTOTB_TVIN_m, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(32, &tcl_file.m_depth);
aesl_fh.write(AUTOTB_TVIN_m, end_str());
}

#endif
// print mlen Transactions
{
aesl_fh.write(AUTOTB_TVIN_mlen, begin_str(AESL_transaction));
{
    sc_bv<64> __xlx_tmp_lv = *((long long*)&__xlx_apatb_param_mlen);
aesl_fh.write(AUTOTB_TVIN_mlen, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.mlen_depth);
aesl_fh.write(AUTOTB_TVIN_mlen, end_str());
}

unsigned __xlx_offset_byte_param_ad = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_ad, 'b');
transaction<8> tr(32);
  __xlx_offset_byte_param_ad = 0*1;
  if (__xlx_apatb_param_ad) {
tr.import<1>((char*)__xlx_apatb_param_ad, 32, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_ad, tr.p, tr.tbytes);
}

  tcl_file.set_num(32, &tcl_file.ad_depth);
#else
// print ad Transactions
{
aesl_fh.write(AUTOTB_TVIN_ad, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_ad = 0*1;
  if (__xlx_apatb_param_ad) {
    for (int j = 0  - 0, e = 32 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_ad)[j];
aesl_fh.write(AUTOTB_TVIN_ad, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(32, &tcl_file.ad_depth);
aesl_fh.write(AUTOTB_TVIN_ad, end_str());
}

#endif
// print adlen Transactions
{
aesl_fh.write(AUTOTB_TVIN_adlen, begin_str(AESL_transaction));
{
    sc_bv<64> __xlx_tmp_lv = *((long long*)&__xlx_apatb_param_adlen);
aesl_fh.write(AUTOTB_TVIN_adlen, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.adlen_depth);
aesl_fh.write(AUTOTB_TVIN_adlen, end_str());
}

// print nsec Transactions
{
aesl_fh.write(AUTOTB_TVIN_nsec, begin_str(AESL_transaction));
{
    sc_bv<8> __xlx_tmp_lv = *((char*)__xlx_apatb_param_nsec);
aesl_fh.write(AUTOTB_TVIN_nsec, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.nsec_depth);
aesl_fh.write(AUTOTB_TVIN_nsec, end_str());
}

unsigned __xlx_offset_byte_param_npub = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_npub, 'b');
transaction<8> tr(16);
  __xlx_offset_byte_param_npub = 0*1;
  if (__xlx_apatb_param_npub) {
tr.import<1>((char*)__xlx_apatb_param_npub, 16, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_npub, tr.p, tr.tbytes);
}

  tcl_file.set_num(16, &tcl_file.npub_depth);
#else
// print npub Transactions
{
aesl_fh.write(AUTOTB_TVIN_npub, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_npub = 0*1;
  if (__xlx_apatb_param_npub) {
    for (int j = 0  - 0, e = 16 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_npub)[j];
aesl_fh.write(AUTOTB_TVIN_npub, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(16, &tcl_file.npub_depth);
aesl_fh.write(AUTOTB_TVIN_npub, end_str());
}

#endif
unsigned __xlx_offset_byte_param_k = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_k, 'b');
transaction<8> tr(16);
  __xlx_offset_byte_param_k = 0*1;
  if (__xlx_apatb_param_k) {
tr.import<1>((char*)__xlx_apatb_param_k, 16, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_k, tr.p, tr.tbytes);
}

  tcl_file.set_num(16, &tcl_file.k_depth);
#else
// print k Transactions
{
aesl_fh.write(AUTOTB_TVIN_k, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_k = 0*1;
  if (__xlx_apatb_param_k) {
    for (int j = 0  - 0, e = 16 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_k)[j];
aesl_fh.write(AUTOTB_TVIN_k, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(16, &tcl_file.k_depth);
aesl_fh.write(AUTOTB_TVIN_k, end_str());
}

#endif
unsigned __xlx_offset_byte_param_st = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_st, 'b');
transaction<64> tr(5);
  __xlx_offset_byte_param_st = 0*8;
  if (__xlx_apatb_param_st) {
tr.import<8>((char*)__xlx_apatb_param_st, 5, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_st, tr.p, tr.tbytes);
}

  tcl_file.set_num(5, &tcl_file.st_depth);
#else
// print st Transactions
{
aesl_fh.write(AUTOTB_TVIN_st, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_st = 0*8;
  if (__xlx_apatb_param_st) {
    for (int j = 0  - 0, e = 5 - 0; j != e; ++j) {
sc_bv<64> __xlx_tmp_lv = ((long long*)__xlx_apatb_param_st)[j];
aesl_fh.write(AUTOTB_TVIN_st, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(5, &tcl_file.st_depth);
aesl_fh.write(AUTOTB_TVIN_st, end_str());
}

#endif
CodeState = CALL_C_DUT;
int ap_return = crypto_aead_encrypt_h_hw_stub_wrapper(__xlx_apatb_param_c, __xlx_apatb_param_clen, __xlx_apatb_param_m, __xlx_apatb_param_mlen, __xlx_apatb_param_ad, __xlx_apatb_param_adlen, __xlx_apatb_param_nsec, __xlx_apatb_param_npub, __xlx_apatb_param_k, __xlx_apatb_param_st);
CodeState = DUMP_OUTPUTS;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_c, 'b');
transaction<8> tr(48);
  __xlx_offset_byte_param_c = 0*1;
  if (__xlx_apatb_param_c) {
tr.import<1>((char*)__xlx_apatb_param_c, 48, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVOUT_c, tr.p, tr.tbytes);
}

  tcl_file.set_num(48, &tcl_file.c_depth);
#else
// print c Transactions
{
aesl_fh.write(AUTOTB_TVOUT_c, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_c = 0*1;
  if (__xlx_apatb_param_c) {
    for (int j = 0  - 0, e = 48 - 0; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_c)[j];
aesl_fh.write(AUTOTB_TVOUT_c, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(48, &tcl_file.c_depth);
aesl_fh.write(AUTOTB_TVOUT_c, end_str());
}

#endif
// print clen Transactions
{
aesl_fh.write(AUTOTB_TVOUT_clen, begin_str(AESL_transaction));
{
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_clen);
aesl_fh.write(AUTOTB_TVOUT_clen, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.clen_depth);
aesl_fh.write(AUTOTB_TVOUT_clen, end_str());
}

// print return Transactions
{
aesl_fh.write(AUTOTB_TVOUT_return, begin_str(AESL_transaction));
sc_bv<32> __xlx_tmp_lv = ((int*)&ap_return)[0];
aesl_fh.write(AUTOTB_TVOUT_return, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));

  tcl_file.set_num(1, &tcl_file.return_depth);
aesl_fh.write(AUTOTB_TVOUT_return, end_str());
}

CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
return ap_return;
}

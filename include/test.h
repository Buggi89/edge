#ifndef TEST_H
#define TEST_H

void f_assert_equal_i(int, int, string, int line, const string file);
void f_assert_equal_d(double, double, string, double, int line, const string file);
void f_assert_equal_s(string, string, string, int line, const string file);

#define assert_equal_i(act, exp, mes) do { \
  f_assert_equal_i(act,exp,mes,__LINE__,__FILE__); \
} while(0)

#define assert_equal_d(act, exp, mes) do { \
  f_assert_equal_d(act,exp,mes,EPSILON,__LINE__,__FILE__); \
} while(0)

#define assert_equal_dp(act, exp, mes, prec) do { \
  f_assert_equal_d(act,exp,mes,prec,__LINE__,__FILE__); \
} while(0)

#define assert_equal_s(act, exp, mes) do { \
  f_assert_equal_s(act,exp,mes,__LINE__,__FILE__); \
} while(0)

#define assert_fail(command, name) do { \
try {\
  command;\
} catch (string *msg) { f_assert_equal_i(1,1, name,__LINE__,__FILE__); delete msg; break; }\
f_assert_equal_s("no exception", "exception", name,__LINE__,__FILE__);\
} while(0)

#define assert_fail_message(command, message, name) do { \
try {\
  command;\
} catch (string *msg) { f_assert_equal_s(*msg, message, name,__LINE__,__FILE__); delete msg; break; }\
f_assert_equal_s("no exception", "exception", name, __LINE__,__FILE__);\
} while(0)

#endif // TEST_H


#ifndef TEST_H
#define TEST_H

void assert_equal(int, int, string);
void assert_equal(double, double, string, double);
void assert_equal(string, string, string);

#define assert_fail(command, name) do { \
try {\
  command;\
} catch (string *msg) { assert_equal(1,1, name); break; }\
assert_equal("no exception", "exception", name);\
} while(0)

#define assert_fail_message(command, message, name) do { \
try {\
  command;\
} catch (string *msg) { assert_equal(*msg, message, name); break; }\
assert_equal("no exception", "exception", name);\
} while(0)

#endif // TEST_H


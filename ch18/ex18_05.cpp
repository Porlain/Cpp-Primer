/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-21 16:39:25
 */
#include <exception>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

using namespace std;

int main()
{
    try
    {
        // use of the C++ standard library
    }
    catch (bad_cast &r)
    {
        cout << r.what();
        abort();
    }
    catch (range_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (underflow_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (overflow_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (runtime_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (length_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (out_of_range &r)
    {
        cout << r.what();
        abort();
    }
    catch (invalid_argument &r)
    {
        cout << r.what();
        abort();
    }
    catch (domain_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (logic_error &r)
    {
        cout << r.what();
        abort();
    }
    catch (bad_alloc &r)
    {
        cout << r.what();
        abort();
    }
    catch (exception &r)
    {
        cout << r.what();
        abort();
    }

    return 0;
}

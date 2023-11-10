/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-09 11:10:04
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#ifndef CP5_ex7_31_h
#define CP5_ex7_31_h

class Y;

class X {
    Y* y = nullptr;
};

class Y {
    X x;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 23:52:52 by faikhan           #+#    #+#             */
/*   Updated: 2026/06/30 22:46:00 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



void identify(Base &p) {
    try {
        void(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e) {}
    try {
        void(dynamic_cast<B&>(p));
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e) {}
    try {
        void(dynamic_cast<C&>(p));
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e) {}
}

void identify(Base *p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else 
        std::cout << "Unknown" << std::endl;
    }


Base *generate(void) {
    srand(time(NULL));
    int r = rand() % 3;
    if(r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else 
        return new C();
}

int main(void) {
    Base *p = generate();
    std::cout << "Base pointer identification: " << std::endl;
    identify(p);
    std::cout << "Base reference identification: " << std::endl;
    identify(*p);
    delete p;
    return (0);
}
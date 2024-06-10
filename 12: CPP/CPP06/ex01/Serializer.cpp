/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:18:27 by waziz             #+#    #+#             */
/*   Updated: 2024/05/29 20:51:37 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& affect) {
	(void)affect;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {return reinterpret_cast<uintptr_t>(ptr);}
Data*	Serializer::deserialize(uintptr_t raw) {return reinterpret_cast<Data*>(raw);}
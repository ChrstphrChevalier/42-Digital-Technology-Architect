/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:42:50 by waziz             #+#    #+#             */
/*   Updated: 2024/06/19 12:55:21 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Webserv.hpp"

static void	trim(string *str) {
	(*str).erase(0, (*str).find_first_not_of(" \t"));
    (*str).erase((*str).find_last_not_of(" \t") + 1);
}

void	Webserv::parseConfig(const string& config) {
	if (config.size() > 4 && config.substr(config.size() - 4) == ".ini") {
		ifstream ifs(config);
		if (!ifs.is_open())
			throw runtime_error("Impossible to open the file");
		string line;
		vector<pair<string, string> > current;
		while (getline(ifs, line)) {
			if (line.empty())
				continue;
			if (line == "[Server]") {
				if (!current.empty()) {
					_settings.push_back(current);
					current.clear();
				}
				continue;
			}
			stringstream ss(line);
			string key, value;
			if (getline(ss, key, '=') && getline(ss, value)) {
				trim(&key);
				trim(&value);
				if (key.empty() || value.empty()) {
					cout << YLLW << "What is this shit -> " << ORNG << line << RST << endl;
					throw runtime_error("Invalid configuration parameter");
				}
				current.push_back(make_pair(key, value));
			}
			else {
				cout << YLLW << "What is this shit -> " << ORNG << line << RST << endl;
				throw runtime_error("Invalid configuration parameter");
			}
		}
		_settings.push_back(current);
	}
	else
		throw runtime_error("Invalid file, expected : 'config.ini'");
}

void	Webserv::addServ() {
	vector<vector<pair<string, string> > >::iterator it = _settings.begin();
	int i = 1;
	while (it != _settings.end()) {
		cout << BLUE << "SERVER " << i << " : " << RST << GRY2 << ITAL << "configuration..." << RST << endl;
		_servers.push_back(Server(*it));
		it++;
		i++;
	}
}

Webserv::Webserv(const string& config) {
	parseConfig(config);
	addServ();
	_listen = new Listen(_servers); 
}

Webserv::~Webserv() {
	delete _listen;
}
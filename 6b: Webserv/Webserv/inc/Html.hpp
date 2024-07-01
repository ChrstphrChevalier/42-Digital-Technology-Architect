/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Html.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:30:35 by waziz             #+#    #+#             */
/*   Updated: 2024/07/01 21:06:18 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "lib.hpp"

using namespace std;

class Html {
	private:
		map<string, string>	_extensions;
		map<int, string>	_codeResp;
		map<int, string>	_errPage;

	public:
		Html() {
			Extensions();
			CodeResp();
			ErrPage();
		}
		~Html() {
			_extensions.clear();
			_codeResp.clear();
			_errPage.clear();
		}

	/*----------------------------------------------------------------------*/
	/*            			Init Html				*/
	//									//
	/*			|	Extensions  	|			*/
	/*			|	 CodeResp	|			*/
	/*			|	  ErrPage 	|			*/
	/*----------------------------------------------------------------------*/

		void	Extensions() {
			_extensions[".html"] = "text/html; charset=UTF-8";
			_extensions[".txt"] = "text/plain; charset=UTF-8";
			_extensions[".css"] = "text/css; charset=UTF-8";
			_extensions[".js"] = "application/javascript; charset=UTF-8";
			_extensions[".json"] = "application/json; charset=UTF-8";
			_extensions[".xml"] = "application/xml; charset=UTF-8";
			_extensions[".jpeg"] = "image/jpeg";
			_extensions[".jpg"] = "image/jpeg";
			_extensions[".png"] = "image/png";
			_extensions[".gif"] = "image/gif";
			_extensions[".pdf"] = "application/pdf";
			_extensions[".zip"] = "application/zip";
			_extensions[".tar"] = "application/x-tar";
			_extensions[".gz"] = "application/gzip";
			_extensions[".mp3"] = "audio/mpeg";
			_extensions[".mp4"] = "video/mp4";
			_extensions[".wav"] = "audio/wav";
			_extensions[".avi"] = "video/x-msvideo";
			_extensions[".mpeg"] = "video/mpeg";
			_extensions[".webm"] = "video/webm";
			_extensions[".csv"] = "text/csv";
			_extensions[".xhtml"] = "application/xhtml+xml";
		}

		void	CodeResp() {
			_codeResp[200] = "HTTP/1.1 200 OK";
			_codeResp[201] = "HTTP/1.1 201 Created";
			_codeResp[204] = "HTTP/1.1 204 No Content";
			_codeResp[301] = "HTTP/1.1 301 Moved Permanently";
			_codeResp[302] = "HTTP/1.1 302 Found";
			_codeResp[304] = "HTTP/1.1 304 Not Modified";
			_codeResp[400] = "HTTP/1.1 400 Bad Request";
			_codeResp[401] = "HTTP/1.1 401 Unauthorized";
			_codeResp[403] = "HTTP/1.1 403 Forbidden";
			_codeResp[404] = "HTTP/1.1 404 Not Found";
			_codeResp[405] = "HTTP/1.1 405 Method Not Allowed";
			_codeResp[408] = "HTTP/1.1 408 Request Timeout";
			_codeResp[411] = "HTTP/1.1 411 Length Required";
			_codeResp[413] = "HTTP/1.1 413 Payload Too Large";
			_codeResp[414] = "HTTP/1.1 414 URI Too Long";
			_codeResp[415] = "HTTP/1.1 415 Unsupported Media Type";
			_codeResp[416] = "HTTP/1.1 416 Range Not Satisfiable";
			_codeResp[500] = "HTTP/1.1 500 Internal Server Error";
			_codeResp[501] = "HTTP/1.1 501 Not Implemented";
			_codeResp[502] = "HTTP/1.1 502 Bad Gateway";
			_codeResp[503] = "HTTP/1.1 503 Service Unavailable";
			_codeResp[504] = "HTTP/1.1 504 Gateway Timeout";
			_codeResp[505] = "HTTP/1.1 505 HTTP Version Not Supported";
		}

		void	ErrPage() {
			_errPage[200] = "OK";
			_errPage[201] = "Created";
			_errPage[204] = "No Content";
			_errPage[301] = "Moved Permanently";
			_errPage[302] = "Found";
			_errPage[304] = "Not Modified";
			_errPage[400] = "Bad Request";
			_errPage[401] = "Unauthorized";
			_errPage[403] = "Forbidden";
			_errPage[404] = "Not Found";
			_errPage[405] = "Method Not Allowed";
			_errPage[408] = "Request Timeout";
			_errPage[411] = "Length Required";
			_errPage[413] = "Payload Too Large";
			_errPage[414] = "URI Too Long";
			_errPage[415] = "Unsupported Media Type";
			_errPage[416] = "Range Not Satisfiable";
			_errPage[500] = "Internal Server Error";
			_errPage[501] = "Not Implemented";
			_errPage[502] = "Bad Gateway";
			_errPage[503] = "Service Unavailable";
			_errPage[504] = "Gateway Timeout";
			_errPage[505] = "HTTP Version Not Supported";
		}

	/*----------------------------------------------------------------------*/
	/*            		  Error Page Construction			*/
	/*----------------------------------------------------------------------*/

		string generateErrPage(int errorCode, const string& name) const {
			ostringstream oss;
			oss << errorCode;
			string errCode = oss.str();

			string errorMessage = _errPage.at(errorCode);

			string html;
			html += "<!DOCTYPE html>\n";
			html += "<html lang=\"en\">\n";
			html += "<head>\n";
			html += "    <meta charset=\"UTF-8\">\n";
			html += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
			html += "    <title>" + errCode + "</title>\n";
			html += "    <style>\n";
			html += "        body {\n";
			html += "            background-color: #add8e6; /* Couleur bleu plus prononcée */\n";
			html += "            color: #333333;\n";
			html += "            font-family: Arial, sans-serif;\n";
			html += "            display: flex;\n";
			html += "            justify-content: center;\n";
			html += "            align-items: flex-start; /* Alignement en haut */\n";
			html += "            height: 100vh;\n";
			html += "            margin: 0;\n";
			html += "            padding-top: 25vh; /* Ajustement de la position pour être entre le milieu et le haut */\n";
			html += "            text-align: center; /* Centrer le texte */\n";
			html += "        }\n";
			html += "        h1 {\n";
			html += "            font-size: 3em;\n";
			html += "            margin: 0;\n";
			html += "        }\n";
			html += "        .signature {\n";
			html += "            color: #f5f5f5; /* Blanc cassé */\n";
			html += "            font-style: italic;\n";
			html += "            font-family: 'Brush Script MT', cursive; /* Police attachée */\n";
			html += "            font-size: 1.5em;\n";
			html += "            margin-top: 10px; /* Espacement au-dessus de la signature */\n";
			html += "        }\n";
			html += "    </style>\n";
			html += "</head>\n";
			html += "<body>\n";
			html += "    <div>\n";
			html += "        <h1>" + errCode + " " + errorMessage + "</h1>\n";
			html += "        <div class=\"signature\">made in " + name + "</div>\n";
			html += "    </div>\n";
			html += "</body>\n";
			html += "</html>";

			return html;
		}

	/*----------------------------------------------------------------------*/
	/*            		       Create Header				*/
	//									//
	/*			       |   Date   |				*/
	//									//
	/*			     - generateHeader - 			*/
	/*----------------------------------------------------------------------*/

string Date() const {
    time_t currentTime = time(0);
    tm* localTime = localtime(&currentTime);

    const char* daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const char* monthsOfYear[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    ostringstream date;
    date << daysOfWeek[localTime->tm_wday] << ", "
         << (localTime->tm_mday < 10 ? "0" : "") << localTime->tm_mday << " "
         << monthsOfYear[localTime->tm_mon] << " "
         << (localTime->tm_year + 1900) << " "
         << (localTime->tm_hour < 10 ? "0" : "") << localTime->tm_hour << ":"
         << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << ":"
         << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec;

    return date.str();
}

		/* Function Master */
		string generateHeader(int codeResp, const string& name, const string& extension, size_t contentLength) const {
			ostringstream oss;
			oss << contentLength;
			string cL = oss.str();

			string cR;

			map<int, string>::const_iterator it = _codeResp.find(codeResp);
			if (it != _codeResp.end())
				cR = it->second;

			string header;

			header += cR + "\r\n";    
			header += "Date: " + Date() + "\r\n";
			header += "Server:" + name + "\r\n";
			header += "Content-Type: " + _extensions.at(extension) + "\r\n";
			header += "Content-Length: " + cL + "\r\n";
			header += "Connection: close\r\n";
			header += "\r\n";

			return header;
		}

	/*----------------------------------------------------------------------*/
	/*            		      Create Listing				*/
	//									//
	/*			       |   Css   |				*/
	//									//
	/*			     - generateListing - 			*/
	/*----------------------------------------------------------------------*/

		string Css() const {
			string css;
			
			css += "<style>\n";
			css += "    body {\n";
			css += "        background-color: #333;\n";
			css += "        color: #f2f2f2;\n";
			css += "        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n";
			css += "        margin: 0;\n";
			css += "        padding: 20px;\n";
			css += "        text-align: center; /* Centrer le texte dans le corps */\n";
			css += "    }\n";
			css += "    .container {\n";
			css += "        max-width: 800px;\n";
			css += "        margin: 0 auto;\n";
			css += "        border: 1px solid #87CEEB; /* Bleu ciel */\n";
			css += "        border-radius: 10px;\n";
			css += "        padding: 40px;\n";
			css += "        background-color: #222;\n";
			css += "        box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);\n";
			css += "        text-align: left; /* Aligner le texte à gauche dans le container */\n";
			css += "        position: relative; /* Pour positionner les éléments enfants */\n";
			css += "    }\n";
			css += "    .separator {\n";
			css += "        position: absolute;\n";
			css += "        top: 50%; /* Déplacer le trait à la moitié de la hauteur */\n";
			css += "        left: 50%; /* Déplacer le trait à la moitié de la largeur */\n";
			css += "        transform: translate(-50%, -50%); /* Centrer le trait */\n";
			css += "        width: 50%; /* Largeur du trait à 50% de la largeur du container */\n";
			css += "        height: 1px; /* Hauteur du trait */\n";
			css += "        background-color: #f2f2f2; /* Blanc cassé */\n";
			css += "    }\n";
			css += "    h1 {\n";
			css += "        font-size: 48px;\n";
			css += "        margin-bottom: 20px;\n";
			css += "        color: #00e1ff; /* Bleu turquoise */\n";
			css += "        text-align: center; /* Centrer le titre */\n";
			css += "    }\n";
			css += "    ul {\n";
			css += "        list-style-type: none;\n";
			css += "        padding: 0;\n";
			css += "		margin: 0;\n";
			css += "    }\n";
			css += "    li {\n";
			css += "        margin-bottom: 10px;\n";
			css += "        text-align: center; /* Centrer les éléments de la liste */\n";
			css += "    }\n";
			css += "    a {\n";
			css += "        color: #00e1ff; /* Bleu turquoise pour tous les liens */\n";
			css += "        text-decoration: none;\n";
			css += "    }\n";
			css += "    a:hover {\n";
			css += "        text-decoration: underline;\n";
			css += "    }\n";
			css += "    .current-directory {\n";
			css += "        font-weight: bold;\n";
			css += "    }\n";
			css += "    .file {\n";
			css += "        color: #f2f2f2;\n";
			css += "    }\n";
			css += "    .directory {\n";
			css += "        color: #00e1ff; /* Bleu turquoise pour les répertoires */\n";
			css += "    }\n";
			css += "    .path {\n";
			css += "        color: #f2f2f2; /* Blanc cassé pour le chemin */\n";
			css += "        text-align: center; /* Centrer le chemin */\n";
			css += "        margin-top: 20px; /* Espace au-dessus du chemin */\n";
			css += "    }\n";
			css += "</style>\n";

			return css;
		}

		/* Function Master */
		string generateListing(const string& directory, const string& URi) const {
			string html;
			DIR* dir = opendir(URi.c_str());
			if (dir == NULL) {
				perror("opendir");
				return html;
			}

			size_t pos = URi.find_last_of('/');
			string Dir = URi.substr(0, pos);

			size_t parentPos = Dir.find_last_of('/');
			string parentName = Dir.substr(parentPos + 1);

			html += "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\">";
			html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
			html += "<title>Listing : " + directory + "</title>";
			html += Css();
			html += "</head><body>";

			html += "<div class=\"container\">";
			html += "<ul>";
			html += "<li><a class=\"directory\" href=\"" + parentName + "\">>> Parent Directory <<</a></li>";
			html += "</ul>";
			html += "<h1>" + directory + "</h1>";
			html += "<p class=\"path\">" + URi + "</p>";
			html += "<div class=\"separator\"></div>";
			html += "<br />";
			html += "<ul>";

			struct dirent* entry;
			while ((entry = readdir(dir)) != NULL) {
				if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
					string entryPath = URi + "/" + entry->d_name;
					string linkClass = (entry->d_type == DT_DIR) ? "directory" : "file";
					html += "<li><a class=\"" + linkClass + "\" href=\"" + entryPath + "\">" + entry->d_name + "</a></li>";
				}
			}

			html += "</ul>";
			html += "</div>";

			html += "</body></html>";
			closedir(dir);
			return html;
		}
};

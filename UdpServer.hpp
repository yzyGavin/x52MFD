/*
 * Copyright 2014 Michael Sacher
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * =====================================================================================
 *
 *       Filename:  UdpServer.hpp
 *
 *    Description:  Code for communicating with flightgear via UDP 
 *
 *        Created:  21.04.2014 22:31:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Sacher (ms), michael.sacher@performant.ch
 *
 * =====================================================================================
 */

#ifndef  UdpServer_INC
#define  UdpServer_INC

#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

/*
 * =====================================================================================
 *        Class:  UdpServer
 *  Description:  
 * =====================================================================================
 */

#define BUFFER_SIZE 200

class UdpServer
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		UdpServer(int portno);                             /* constructor */
		~UdpServer();                             /* destructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */
		std::string fetch();
		void send(std::string message);

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		boost::asio::io_service io_service;
		boost::asio::ip::udp::socket *socket;
		boost::asio::ip::udp::endpoint remote_endpoint;
		boost::system::error_code error;
		int port;
}; /* -----  end of class UdpServer  ----- */

/*
 * =====================================================================================
 *        Class:  UdpClient
 *  Description:  
 * =====================================================================================
 */
class UdpClient
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		UdpClient (int portno);                             /* constructor */
		~UdpClient ();                             					/* destructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */
		void send(std::string message);

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		boost::asio::io_service io_service;
		boost::asio::ip::udp::socket *socket;
		boost::asio::ip::udp::endpoint remote_endpoint;
		boost::system::error_code error;
		int port;

}; /* -----  end of class UdpClient  ----- */

#endif   /* ----- #ifndef UdpServer_INC  ----- */

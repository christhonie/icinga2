/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012 Icinga Development Team (http://www.icinga.org/)        *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H

namespace icinga {

class Component;

/**
 * Abstract base class for applications.
 *
 * @ingroup base
 */
class I2_BASE_API Application : public Object {
public:
	typedef shared_ptr<Application> Ptr;
	typedef weak_ptr<Application> WeakPtr;

	Application(void);
	~Application(void);

	static Application::Ptr GetInstance(void);

	int Run(int argc, char **argv);

	virtual int Main(const vector<string>& args) = 0;

	static void Shutdown(void);

	shared_ptr<Component> LoadComponent(const string& path,
	    const ConfigObject::Ptr& componentConfig);
	void RegisterComponent(const shared_ptr<Component>& component);
	void UnregisterComponent(const shared_ptr<Component>& component);
	shared_ptr<Component> GetComponent(const string& name) const;
	void AddComponentSearchDir(const string& componentDirectory);

	static bool IsDebugging(void);

	static bool IsMainThread(void);

protected:
	void RunEventLoop(void);
	string GetExePath(void) const;

private:
	static Application::Ptr m_Instance; /**< The application instance. */

	static bool m_ShuttingDown; /**< Whether the application is in the process of
				  shutting down. */
	map< string, shared_ptr<Component> > m_Components; /**< Components that
					were loaded by the application. */
	vector<string> m_Arguments; /**< Command-line arguments */
	static bool m_Debugging; /**< Whether debugging is enabled. */
	static boost::thread::id m_MainThreadID; /**< ID of the main thread. */

#ifndef _WIN32
	static void SigIntHandler(int signum);
#else /* _WIN32 */
	static BOOL WINAPI CtrlHandler(DWORD type);
#endif /* _WIN32 */
};

}

#endif /* APPLICATION_H */

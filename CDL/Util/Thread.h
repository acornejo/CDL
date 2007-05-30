#ifndef __CDL_THREAD_H__
#define __CDL_THREAD_H__

#include <CDL/defs.h>
#include <CDL/Util/NonCopyable.h>

namespace CDL
{
    class DLL_API Thread
    {
        protected:
            void    *m_handle;
            bool     m_alive;
            unsigned int m_id;
            static void *entryPoint(void *);

        public:
            Thread();
            virtual ~Thread();
            virtual void start();
            virtual void stop();
            void join();
            static void yield();
            static unsigned int currentThread();
            const unsigned int &getID() const;
            virtual void run()=0;
            const bool &isAlive() const;
    };
}

#endif//__CDL_THREAD_H__

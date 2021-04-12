// Copyright (c) 2017-2020, Michael P. Howard
// Copyright (c) 2021, Auburn University
// This file is part of the gsd-vmd project, released under the Modified BSD License.

#ifndef GSDVMD_TESTS_DYNAMIC_LIBRARY_H_
#define GSDVMD_TESTS_DYNAMIC_LIBRARY_H_

#include <dlfcn.h>
#include <string>

//! Opens a dynamic library on linux
class DynamicLibrary
    {
    public:
        //! Default constructor
        DynamicLibrary()
            : handle_(NULL)
            {
            }

        //! Constructor
        /*!
         * \param lib Library to open
         */
        DynamicLibrary(const std::string& lib)
            : handle_(NULL), lib_(lib)
            {
            }

        //! Destructor
        ~DynamicLibrary()
            {
            close();
            }

        //! Opens the library
        bool open();

        //! Load a symbol from the library
        void* load(const std::string& name) const;

        //! Close the library
        void close();

    private:
        void *handle_; //!< Handle to the library
        std::string lib_;   //!< Name of the library
    };

#endif // GSDVMD_TESTS_DYNAMIC_LIBRARY_H_

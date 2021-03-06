#ifndef Move_GammaScale_H
#define Move_GammaScale_H

#include "RlMove.h"
#include "TypedDagNode.h"

#include <ostream>
#include <string>

namespace RevLanguage {
    
    
    /**
     * The RevLanguage wrapper of the gamma scaling move.
     *
     * The RevLanguage wrapper of the gamma scaling move simply
     * manages the interactions through the Rev with our core.
     * That is, the internal move object can be constructed and hooked up
     * in a DAG-nove (variable) that it works on.
     *
     *
     * @copyright Copyright 2009-
     * @author The RevBayes Development Core Team (Jeremy Brown)
     * @since 2014-01-28, version 1.0
     *
     */
    class Move_GammaScale : public Move {
        
    public:
        
        Move_GammaScale(void);                                                                                                                       //!< Default constructor
        
        // Basic utility functions
        virtual Move_GammaScale*                    clone(void) const;                                                                          //!< Clone object
        void                                        constructInternalObject(void);                                                              //!< We construct the a new internal gamma scale move
        static const std::string&                   getClassType(void);                                                                         //!< Get Rev type
        static const TypeSpec&                      getClassTypeSpec(void);                                                                     //!< Get class type spec
        std::string                                 getMoveName(void) const;                                                                    //!< Get the name used for the constructor function in Rev.
        const MemberRules&                          getParameterRules(void) const;                                                              //!< Get member rules (const)
        virtual const TypeSpec&                     getTypeSpec(void) const;                                                                    //!< Get language type of the object
        virtual void                                printValue(std::ostream& o) const;                                                          //!< Print value (for user)
        
    protected:
        
        void                                        setConstParameter(const std::string& name, const RevPtr<const RevVariable> &var);           //!< Set member variable
        
        RevPtr<const RevVariable>                   x;                                                                                          //!< The variable on which the move works
        RevPtr<const RevVariable>                   lambda;                                                                                     //!< The tuning parameter
        RevPtr<const RevVariable>                   tune;                                                                                       //!< If autotuning should be used.
        std::vector<std::string>                    getHelpAuthor(void) const;  //!< Get the author(s) of this function
        std::vector<std::string>                    getHelpSeeAlso(void) const; //!< Get suggested other functions
        std::string                                 getHelpDescription(void) const;  //!< Get the description for this function
        std::string                                 getHelpExample(void) const; //!< Get an executable and instructive example
    };
    
}

#endif

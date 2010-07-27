(docfun defforeign function "
Args: (func-name module c-entry parameter-types result-type)
Defines FUNC-NAME as a foreign language function. MODULE is a foreign
module object loaded by load-foreign function. C_ENTRY is a string
expressing the function entry name in the module. In unix C, note
that underscore \"_\" is usually added as a prefix of external symbols.
PARAMETER-TYPES is a list of parameter type specifications, which are
either of :integer, :float, :string or (:string n) where n is an integer.
When these specifications are omitted, default type conversion is taken
by euslisp's funcall.  On the other hand RESULT-TYPE cannot be omitted
since euslisp cannot infer the type of an object returned from
C functions.")

(docfun load-foreign  macro "
Args: (file)
FILE is loaded as a foreign language object module.
LOAD-FOREIGN differs from LOAD, that the former does not call initialization
routine in the object module, and after the loading, LOAD-FOREIGN also
reads the symbol table for all the external symbols defined in the module.
This is necessary to make entries to these functions from lisp functions.
LOAD-FOREIGN returns foreign-module object which can be used for
successive defforeign'")

(docfun defun-c-callable macro "
Args: (func-name parameters result-type &rest body)
Defines FUNC-NAME symbol as a function callable from foreign languages.
PARAMETERS is a list of param-specifications each of which are consisted of
a variable name and its type specifier keyword. RESULT-TYPE is also
one of type specifier keywords, :integer, :float or :string.
BODY is usual lisp forms.")

(docfun rotate-matrix function "
Args: (matrix radian axis &optional (world-p nil) (result (make-matrix)))
Rotates matrix around the given axis by radian. Axis may be one of :x, :y, :z,
0,1,2 or arbitrary floatvector which represents the rotation axis.
If world-p is nil, the rotation is taken in the local coordinates, i.e.,
the rotation matrix is multiplied  from the right, and world-p is non-nil,
vice-versa. If result is specified, it must be a matrix.")

(docfun m* function "
Args: (m1 m2 &optional result)
Two matrices are multiplied to produce result, i.e., result=m1*m2.")

(docfun unix:stat function "
Args: (filename)
A list of creation_time, modification_time, access_time, size,
group-id, user-id, links, rdev, dev, inode, mode of this file.")







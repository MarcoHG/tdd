TDD for Embedded C

## Ported to Eclipse project
**Create some variables**\
- `unity_build` build variable `/home/marco/Documents/edu/tdd/gitTDD/jg/code/unity.framework` fro both builds: Build/Release
- `UNITY_FRAMEWORK_LOC` path variable `/home/marco/Documents/edu/tdd/gitTDD/jg/code/unity.framework`

**Add Unity and fixture source files:**\
In Project properties - C/C++ General -  Path and Symbols in Source Location tab add LinkFolder
- unity_src that links to `UNITY_FRAMEWORK_LOC/src`
- unity_fixture_src linking to `UNITY_FRAMEWORK_LOC/extras/src`

**Include headers**\	
This also allows to source level debug into unity, include:
-`"${unity_build}/extras/fixture/src`
-`"${unity_build}/src"`

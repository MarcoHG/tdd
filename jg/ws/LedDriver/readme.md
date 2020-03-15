# TDD for Embedded C

## Ported to Eclipse project
**Create some variables**
- `unity_build` build variable `/home/marco/Documents/edu/tdd/gitTDD/jg/code/unity.framework` for both builds: Build/Release
- `UNITY_FRAMEWORK_LOC` path variable `/home/marco/Documents/edu/tdd/gitTDD/jg/code/unity.framework`

**Add Unity and fixture source files:**  
In Project properties - C/C++ General -  Path and Symbols in Source Location tab add LinkFolder
- unity_src that links to `UNITY_FRAMEWORK_LOC/src`
- unity_fixture_src linking to `UNITY_FRAMEWORK_LOC/extras/src`

**Include headers**  
This also allows to explore source level debug into unity, include:
-`"${unity_build}/extras/fixture/src`
-`"${unity_build}/src"`

## LED Driver Test
- All LEDs are off after the driver is initialized
- A single LED can be turned on
- A single LED can be turned off
- Multiple LEDs can be turned on/off
- Turn on all LEDs
- Turn off all LEDs
- Query LED state
- Check boundary values
- Check out-of-boundary values

## Test Drive the Interface Before the Internals


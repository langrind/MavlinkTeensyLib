# MavlinkTeensyLib

This project provides directories that you can move to your Arduino
Sketchbook `libraries/` directory, thus allowing you to use MAVLink in
any sketch.

[Why is this not simply an Arduino library ZIP file?](Excuses).

Two directories are provided:

* `mavlink` - MAVLink 1.0
* `mavlink2` - MAVLink 2.0

Copy one or both to the `libraries` folder inside your sketchbook, as
described [here](https://www.arduino.cc/en/guide/libraries) or TLDR:

* Use Arduino IDE Preference to find your Sketchbook
* `cp -R mavlink mavlink2 <Sketchbook>/libraries`

Then you can simply include one or the other header file in your
sketch:

```
#include "mavlink.h"
```

or

```
#include "mavlink2.h"
```

*NOTE* If you don't need MAVLink 1.0, you can rename the `mavlink2`
directory `mavlink` and instead of `mavlink2.h` call it `mavlink.h`.

## What's in Those Directories?

The directories are the output of `mavgen.py` (part of the [MAVLink
toolchain](https://github.com/mavlink/mavlink/)) using the message
definitions from that repo. It is likely that the specific mavlink
protocol version and dialect isn't exactly what you need. It is easy
to change - re-run the generator as you see fit, and replace the
`mavlink` and/or `mavlink2` directory with your newly generated
directory. See the directions in the next section to select the
dialect you need.

## Changing Dialects or Using a Freshly Generated MAVLink Directory

The procedure is the same regardless of whether you have regenerated
the mavlink directory, or you are just selecting a different dialect.

The included shell script `use_dialect.sh` changes dialects for
you. Run it in the `mavlink` or `mavlink2` subdir with a single
argument to tell it the dialect subdirectory to use, in this case
`common`:

```
cd $MYSKETCHBOOK/libraries/mavlink 
$MYMAVLINKTEENSYLIB_CLONE/use_dialect.sh common
```

If you can't run `use_dialect.sh`, it's easy to do it by hand. In
either directory you will see generic header files and
subdirectories. The subdirectories are individual
dialects. `use_dialect.sh` copies the `mavlink.h` file up one level,
if in `mavlink2`, renaming it to `mavlink2.h`. For instance, to select
common:

```
cd <sketchbook>/libraries/mavlink2
cp common/mavlink.h mavlink2.h
```

Then, it edits the relocated file to account for the move, by inserting
the subdirectory in each #include, thus changing:

```
#include "version.h"
#include "common.h"
```

to

```
#include "common/version.h"
#include "common/common.h"
```

## Usage and Examples

See the very simple examples in `examplev1` and `examplev2`. They are
identical except that one includes `mavlink2.h` instead of
`mavlink.h`. Each contains the same sketch.

The sketch initializes Serial for a debug stream ("console") and
Serial1 for the mavlink connection ("telem"). Both are set to 115,200
bps.

The sketch loop polls for Mavlink input and ignores everything except
heartbeats. The sketch sends a heartbeat once per second. That's it.

## Excuses

These two goals appear to be in conflict:

* make an Arduino library that you can zip up and make available to be
  installed via the Arduino IDE's library manager. [See 
  here.](https://www.arduino.cc/en/guide/libraries) 
* Use the MAVLink code as produced by `mavgen.py` with little or no
  change to file content or organization

I chose to preserve the MAVLink code. Mayber there's a way to do both,
please tell me if you know it.

## Authors

* **[mjs513](https://github.com/mjs513)** - original author
* **[Nik Langrind](https://github.com/langrind)** - adapter

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgements

This is a MAVLink library for use in any Arduino project. The [repo
from which I forked
it](https://github.com/mjs513/Mavlink-Rover-Teensy3.x) used the
library in a Rover application. I wanted just the library so that I
can pull it into different projects. Also, it's useful to have
something that is mostly infrastructure and documentation, as opposed
to a full application. But I still want to tip the cap to **mjs513**
because that Rover project is cool, and inspired me to learn some
things.


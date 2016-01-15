; $Id$
api = 2
core = 7.x

; The main distribution we're using
projects[panopoly][type] = core

; Include these other makefiles:
includes[ssu-modules] = "ssu-modules.make"
includes[ssu-modules-buildamodule] = "ssu-modules-buildamodule.make"

; includes[ssu-modules-pinned] = "ssu-modules-pinned.make"
includes[ssu-libraries] = "ssu-libraries.make"

; examples of all the things are here:
; https://www.drupal.org/node/1432374

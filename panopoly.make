; $Id$
api = 2
core = 7.x

; The main distribution we're using
projects[panopoly][type] = core

; Include these other makefiles:
includes[panopoly-modules] = "panopoly-modules.make"

; includes[panopoly-modules-pinned] = "panopoly-modules-pinned.make"
includes[panopoly-libraries] = "panopoly-libraries.make"

; examples of all the things are here:
; https://www.drupal.org/node/1432374

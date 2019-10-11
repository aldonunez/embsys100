I choose to describe an electronic door lock found in my office building.

I believe that the purpose of this lock is to control entry to the bathroom in
a way that's convenient for tenants and building management. Thus it uses a key
code. This allows the code to be changed as often as needed without having to
distribute new physical keys.

The components that can be seen are:

- a pad with twelve keys, to input access codes and control the lock.
- a light that shows the current state of the lock.
- a handle to turn that opens the door, once the correct code is entered.
- a keyhole for use as a back up.
- a bolt that fits into a strike plate in the door frame.

Components that can be assumed to be in the door lock are:

- a microcontroller to process key pad input, control the mechanics, and show
  the status.
- a mechanical component that engages with the bolt on command from the
  microcontroller.
- a battery to power the electronic components.

Challenges for this embedded system are:

* Response
  * The door lock should perform these actions quickly: respond to key presses,
    report status, engage the handle, and disengage the handle.
* Debuggability
  * The key pad might be able to be used for debugging. But, this might
    interfere with the security demands of the system.
* Reliability
  * Owners should be able to set up codes and test the lock on their own,
    possibly with the help of a manual or guide.
* Program Installation and upgrade
  * Since this device should be as similar as possible to a traditional lock,
    it shouldn't need upgrading; and should be self contained.
* Power consumption
  * The lock should consume as little power as possible to let the battery last
    years.
* Security
  * Only owners should be able to change key codes.
* Cost
  * The cost should be comparable to a traditional lock.

============
Installation
============

.. code-block:: console

   $ git clone http://github.com/mlos/inbus.client.cpp.git
   $ mkdir build 
   $ cd build
   $ cmake ..
   $ make && make install

Packages for FreeBSD and Debian Linux are being considered.

To create the example code for testing, additionaly do:

.. code-block:: console

   $ make pub hello

-------
Testing
-------

 - Make sure you have an Inbus server running.
 - Start a Subscriber client, listening to 'hello-app'. 

   - An example server and client can be found in the `inbus.client.python project <http://github.com/mlos/inbus.client.python/tree/master/examples>`_.
   - In a terminal, run `python server.py`.
   - In another terminal, run `python subscriber.py hello-app`.

 - Run `hello`.
 - The terminal with the subscriber should receive a message.


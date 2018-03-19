=====
Usage
=====

---------
Publisher
---------

The following basic sample code publishes messages to Inbus

.. code-block:: console
   
   #include <inbus/publisher.h>
   ....

   Publisher p("my-app");
   p.publish("payload");

This code assumes that the Inbus server is running on `localhost` on `port 7222 <http://github.com/mlos/inbus/blob/master/docs/protocol.rst#infrastructure>`_.

Also, the application type is defaulted to `0`.

To specify a particular host-port combination, and publish with application type `123`:

.. code-block:: console
   
   #include <inbus/publisher.h>
   ....

   Publisher p("my-app", "192.168.1.23", 8000);
   p.publish("payload", 123);


----------
Subscriber
----------

Currently :doc:`not implemented <bugs>`.

Alternatively, use the `Python client <http://pypi.python.org/pypi/inbus-client/1.0.1/>`_

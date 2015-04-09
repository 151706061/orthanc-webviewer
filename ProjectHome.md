## Introduction ##

This repository contains the source code of a plugin that extends Orthanc with a Web viewer of medical images. The Web viewer is based upon the two following projects:

  * [Cornerstone](https://github.com/chafey/cornerstone), a client-side JavaScript library to display medical images in Web browsers, by [Chris Hafey](mailto:chafey@gmail.com),
  * [GDCM](http://sourceforge.net/projects/gdcm/), an open-source implementation of the DICOM standard with advanced features for image decoding, by [Mathieu Malaterre](mailto:mathieu.malaterre@gmail.com).

Click on the following image to launch a demo video:

[![](http://wiki.orthanc-webviewer.googlecode.com/hg/Screenshot.png)](https://www.youtube.com/watch?v=ub5IxlVqoOE&feature=youtu.be)

## Licensing ##

The code of the Web viewer plugin is licensed under the **Affero General Public License** ([AGPL](https://en.wikipedia.org/wiki/Affero_General_Public_License)). Pay attention to the fact that this license is more restrictive than the license of the [Orthanc core](http://orthanc.googlecode.com/).

## Compilation ##

The procedure to compile these plugins is similar of that for the [core of Orthanc](https://code.google.com/p/orthanc/source/browse/INSTALL?name=Orthanc-0.8.6). The following commands should work for every UNIX-like distribution (including GNU/Linux):

```
# mkdir Build
# cd Build
# cmake .. -DSTATIC_BUILD=ON
# make
```

More detailed build instruction is available [in the source distribution](https://code.google.com/p/orthanc-webviewer/source/browse/Resources/BuildInstructions.txt). The compilation will produce a shared library `OrthancWebViewer` that contains the Web viewer plugin.

Pre-compiled binaries for Microsoft Windows are available on [SourceForge](https://sourceforge.net/projects/orthancserver/files/DevelopmentSnapshots/).


## Usage ##

You of course first have to install Orthanc, with a version above 0.8.6.

Once Orthanc is installed, you must change the [configuration file](https://code.google.com/p/orthanc/wiki/OrthancConfiguration) to tell Orthanc where it can find the plugin: This is done by properly modifying the "`Plugins`" option. You could for instance use the following configuration file:

```json

{
"Name" : "MyOrthanc",
[...]
"Plugins" : [
"/home/user/OrthancWebViewer/Build/libOrthancWebViewer.so"
]
}
```

Orthanc must of course be restarted after the modification of its configuration file. The log will contain an output similar to:

```
# Orthanc ./Configuration.json 
W0226 16:59:10.480226  7906 main.cpp:636] Orthanc version: mainline
[...]
W0226 16:59:10.519664  7906 PluginsManager.cpp:258] Registering plugin 'web-viewer' (version 1.0)
W0226 16:59:10.519696  7906 PluginsManager.cpp:148] Initializing the Web viewer
W0226 16:59:10.520004  7906 PluginsManager.cpp:148] Web viewer using 6 threads for the decoding of the DICOM images
W0226 16:59:10.520021  7906 PluginsManager.cpp:148] Storing the cache of the Web viewer in folder: OrthancStorage/WebViewerCache
W0226 16:59:10.522011  7906 PluginsManager.cpp:148] Web viewer using a cache of 100 MB
[...]
W0226 16:59:10.530807  7906 main.cpp:516] HTTP server listening on port: 8042
W0226 16:59:10.581029  7906 main.cpp:526] DICOM server listening on port: 4242
W0226 16:59:10.581066  7906 main.cpp:533] Orthanc has started
```

Once a series is opened with Orthanc Explorer, a button entitled "`Orthanc Web Viewer`" will appear. It will open the Web viewer.

## Configuration Options ##

The configuration of the Web viewer can be controlled by adding some options:

```json

{
"Name" : "MyOrthanc",
[...]
"Plugins" : [
"/home/user/OrthancWebViewer/Build/libOrthancWebViewer.so"
],
[...]
"WebViewer" : {
"CachePath" : "WebViewerCache",
"CacheSize" : 10,
"Threads" : 4
}
}
```

  * `CachePath` specifies the location of the cache of the Web viewer. By default, the cache is located inside the storage directory of Orthanc.
  * `CacheSize` specifies the maximum size for the cached images, in megabytes. By default, a cache of 100 MB is used.
  * `Threads` specifies the number of threads that are used by the plugin to decode the DICOM images.
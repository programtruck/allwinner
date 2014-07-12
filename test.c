
#include <stdio.h>
 #include <stdlib.h>
 #include </usr/include/vlc/vlc.h>

 int main(int argc, char* argv[])
 {
     libvlc_instance_t * inst;
   //  libvlc_instance_t * inst2;
     libvlc_media_player_t *mp;
   //   libvlc_media_player_t *mp2;
     libvlc_media_t *m;
  //   libvlc_media_t *m2;

     /* Load the VLC engine */
     inst = libvlc_new (0, NULL);
   //   inst2 = libvlc_new (0, NULL);
     /* Create a new item */
     m = libvlc_media_new_location (inst, "http://medias.france24.com/en/vod/2014/07/08/ANGL140708-2046-Live.mp4");
   //   m2 = libvlc_media_new_location (inst, "http://medias.france24.com/en/vod/2014/07/11/ANGL140711-1215-Live_CS.mp4");

     // http://medias.france24.com/en/vod/2014/07/11/MG054520-A-01-20140709.mp4
     //  http://medias.france24.com/en/vod/jt/jt.mp4
     //m = libvlc_media_new_path (inst, "/path/to/test.mov");

     /* Create a media player playing environement */
     mp = libvlc_media_player_new_from_media (m);
  //   mp2 = libvlc_media_player_new_from_media (m2);
     /* No need to keep the media now */
     libvlc_media_release (m);
  //   libvlc_media_release (m2);

 #if 0
     /* This is a non working code that show how to hooks into a window,
      * if we have a window around */
      libvlc_media_player_set_xwindow (mp, xid);
     /* or on windows */
      libvlc_media_player_set_hwnd (mp, hwnd);
     /* or on mac os */
      libvlc_media_player_set_nsobject (mp, view);
  #endif

      /* play the media_player */
        libvlc_media_player_play (mp);
    //     libvlc_media_player_play (mp2);

        sleep (300); /* Let it play a bit */

        /* Stop playing */
        libvlc_media_player_stop (mp);
         libvlc_media_player_stop (mp2);
        /* Free the media_player */
        libvlc_media_player_release (mp);
      //  libvlc_media_player_release (mp2);


        libvlc_release (inst);
      //  libvlc_release (inst2);
        return 0;
    }


#include "CImg.h"

using namespace cimg_library;

// Declare colors
const unsigned char
      white[]  = { 255, 255, 255 },
	  black[] = { 0, 0, 0 },
	  red[] = { 120, 50, 80 },
      yellow[] = { 200, 155, 0 },
	  green[] = { 30, 200, 70 },
	  purple[] = { 175, 32, 186 },
      blue[] = { 55, 140, 185 },
	  grey[] = { 127, 127, 127 };



void first_item(){
	CImg<unsigned char> first_picture("duterte.bmp");
	first_picture.display("Duterte");
}


void second_item(){
	CImg<unsigned char> second_picture("trump.bmp");
	second_picture.display("Trump");
}


void image_resize(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> original;
	original = duterte;
	duterte.resize(duterte.width()/2,duterte.height()/2,1,3);
	(original, duterte).display("Original vs. Small");
}

void image_enlarge(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> original;
	original = duterte;
	duterte.resize(2*duterte.width(),2*duterte.height(),1,3);
	(original, duterte).display("Original vs. Large");
}

void image_darken(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> original;
	original = duterte;
	// Darken each pixel
	for(int i=0;i<duterte.width();i++)
		for(int j=0;j<duterte.height();j++)
           for(int k=0;k<3;k++)
                duterte(i,j,0,k)= std::max(0, duterte(i,j,0,k) - 100);
	// Display
	(original, duterte).display("Original vs. Dark");
}


void image_brighten(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> original;
	original = duterte;
	// Darken each pixel
	for(int i=0;i<duterte.width();i++)
		for(int j=0;j<duterte.height();j++)
           for(int k=0;k<3;k++)
                duterte(i,j,0,k)= std::min(255, duterte(i,j,0,k) + 100);
	// Display
	(original, duterte).display("Original vs. Bright");
}


void image_invert(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> original;
	original = duterte;
	// Darken each pixel
	for(int i=0;i<duterte.width();i++)
		for(int j=0;j<duterte.height();j++)
           for(int k=0;k<3;k++)
                duterte(i,j,0,k)= 255 - duterte(i,j,0,k);
	
	(original, duterte).display("Original vs. Invert");
}



void image_gray(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> gray(duterte.width(), duterte.height(), 1, 1, 0);
	// Darken each pixel
	for(int i=0;i<duterte.width();i++)
		for(int j=0;j<duterte.height();j++){
			int R = (int)duterte(i,j,0,0);
    		int G = (int)duterte(i,j,0,1);
    		int B = (int)duterte(i,j,0,2);
			gray(i,j,0,0)= (int)(0.299*R + 0.587*G + 0.114*B);
		}

	(duterte, gray).display("Original vs. Gray");
}




void print_pixels(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> gray(duterte.width(), duterte.height(), 1, 1, 0);

	for(int i=0;i<duterte.width();i++){
		for(int j=0;j<duterte.height();j++){
			int R = (int)duterte(i,j,0,0);
    		int G = (int)duterte(i,j,0,1);
    		int B = (int)duterte(i,j,0,2);
			printf("{%d,%d,%d} ",R,G,B);
		}
        printf("\n");
    }

	duterte.display("Original vs. Gray");
}


void image_transpose(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> result(duterte.height(), duterte.width(), 1, 3, 0);

	for(int i=0;i<duterte.width();i++){
		for(int j=0;j<duterte.height();j++){
			result(j,i,0)= duterte(i,j,0);
			result(j,i,1)= duterte(i,j,1);
			result(j,i,2)= duterte(i,j,2);
		}
    }

	(duterte,result).display("Original vs. Transpose");
}


void image_rgb(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> r_image(duterte.width(), duterte.height(), 1, 3, 0);
    CImg<unsigned char> g_image(duterte.width(), duterte.height(), 1, 3, 0);
    CImg<unsigned char> b_image(duterte.width(), duterte.height(), 1, 3, 0);

	for(int i=0;i<duterte.width();i++){
		for(int j=0;j<duterte.height();j++){
			r_image(i,j,0)= duterte(i,j,0);
			g_image(i,j,1)= duterte(i,j,1);
			b_image(i,j,2)= duterte(i,j,2);
		}
    }

	(duterte,r_image, g_image, b_image).display("Original vs. RGB Images");
}



void image_blur(){
	CImg<unsigned char> duterte("duterte.bmp");
	(duterte,(duterte.get_blur(4))).display("CImg Blur!");
}


void image_ave(){
	CImg<float> duterte("duterte.bmp");
    CImg<float> trump("trump.bmp");
	CImg<float> result(duterte.width(), duterte.height(), 1, 3, 0);

    // Resize trump
    trump.resize(duterte.width(),duterte.height(),1,3);

	for(int i=0;i<duterte.width();i++){
		for(int j=0;j<duterte.height();j++){
			result(i,j,0)= (duterte(i,j,0) + trump(i,j,0))/2.0f;
			result(i,j,1)= (duterte(i,j,1) + trump(i,j,0))/2.0f;
			result(i,j,2)= (duterte(i,j,2) + trump(i,j,0))/2.0f;
		}
    }

	(duterte,trump,result).display("Originals vs. Average");
}



void image_upside_down(){
	CImg<unsigned char> duterte("duterte.bmp");
    int image_width = duterte.width();
    int image_height = duterte.height();
	CImg<unsigned char> result(image_width, image_height, 1, 3, 0);

	for(int i=0;i<image_width;i++){
		for(int j=0;j<image_height;j++){
			result(i,j,0)= duterte(image_width - i,image_height - j,0);
			result(i,j,1)= duterte(image_width - i,image_height - j,1);
			result(i,j,2)= duterte(image_width - i,image_height - j,2);
		}
    }

	(duterte,result).display("Original vs. Upside Down");
}


void image_color_interchange(){
	CImg<unsigned char> duterte("duterte.bmp");
	CImg<unsigned char> rg_image(duterte.width(), duterte.height(), 1, 3, 0);
    CImg<unsigned char> rb_image(duterte.width(), duterte.height(), 1, 3, 0);

	for(int i=0;i<duterte.width();i++){
		for(int j=0;j<duterte.height();j++){
	
	        // R-G Channel Exchange
			rg_image(i,j,0)= duterte(i,j,1);
			rg_image(i,j,1)= duterte(i,j,0);
			rg_image(i,j,2)= duterte(i,j,2);
            
            // R-B Channel Exchange
			rb_image(i,j,0)= duterte(i,j,2);
			rb_image(i,j,1)= duterte(i,j,1);
			rb_image(i,j,2)= duterte(i,j,0);
		}
    }

	(duterte,rg_image, rb_image).display("Original vs. R-G R-B Exchange Images");	
}



void image_w_gradient(){
	CImg<float> duterte("duterte.bmp");
    CImg<float> gradient("gradient.bmp");
    CImg<float> result;
    gradient.resize(duterte.width(),duterte.height(),1,3);
    result = duterte/2.0f + gradient;                                                          // Add shading to each channel of 'img1'.
    result.cut(0,255);  // limit to 0-255 range                                                    // Prevent [0,255] overflow.
    (duterte,gradient,result).display();
}




// Run a selected effect
//-----------------------
void start_item(const unsigned int menu_number) {
  switch (menu_number) {
  case 1:
          first_item();
          puts("Calling first item...");
  		  break;
  case 2:
		  second_item();
		  puts("Calling second item...");
          break;
  case 3:
          image_resize();
          puts("Calling third item...");
          break;
  case 4:
          image_enlarge();
          break;
  case 5:
          image_darken();
          break;
  case 6:
          image_brighten();
          break;
  case 7:
          image_blur();
          break;
  case 8:
          image_invert();
          break;
  case 9:
          image_gray();
          break;
  case 10:
          print_pixels();
          break;
  case 11:
          image_transpose();
          break;
  case 12:
          image_rgb();
          break;
  case 13:
          image_ave();
          break;
  case 14:
          image_upside_down();
          break;
  case 15:
          image_color_interchange();
          break;
  case 16:
          image_w_gradient();
          break;
  default:
          break;
  }
}


int main(int argc, char **argv) {

  const unsigned int NUM_OF_ITEMS = 16;
  const unsigned int TEXT_HEIGHT = 22;
  const unsigned int TEXT_INCREMENT = 15;

  unsigned int menu_number = cimg_option("-run",0,0);
  
  if (menu_number)
  	start_item(menu_number);
  else {
    cimg::info();

    // Initial height
    int y0 = 2*TEXT_INCREMENT;
    
    // Set-up the text background with title highlight
    CImg<unsigned char> back("cloud.bmp");
    back.draw_rectangle(0,y0 - 7,back.width() - 1,y0 + 20,white);
    
    // Set-up the text foreground, text, image;
    CImg<unsigned char> fore, text, img;

	fore.assign(back.width(),50,1,1,0).draw_text(20,y0 - 3,"Choose from the following options:",grey,0,1,23);
    (fore+=fore.get_dilate(3).dilate(3)).resize(-100,-100,1,3);

    text.draw_text(1,1,
                   "1. First Item\n"
                   "2. Second Item\n"
                   "3. Reduce Image Size\n"
				   "4. Enlarge Image Size\n"
				   "5. Darken Image\n"
				   "6. Brighten Image\n"
				   "7. Blur Image\n"
				   "8. Invert Image\n"
				   "9. Gray Image\n"
                   "10. Print pixels\n"
				   "11. Transpose image\n"
				   "12. RGB images\n"
                   "13. Average 2 images\n"
                   "14. Upside Down \n"
                   "15. R-B and R-G exchange \n"
				   "16. Image with gradient \n",
                   white,0,1,TEXT_HEIGHT).resize(-100,-100,1,3);
                   
    fore.resize(back,0).draw_image(20,y0 + 3*TEXT_INCREMENT,text|=text.get_dilate(3)>>4);

    CImgDisplay disp(back,"Main Menu",0,false,true);
    disp.move((disp.screen_width() - disp.window_width())/2,(disp.screen_height() - disp.window_height())/2);
    img = back;
	back*=0.15f;
	
    for (y0 += 3*TEXT_INCREMENT; !disp.is_closed() && !disp.is_keyQ() && !disp.is_keyESC(); menu_number = 0) {
    	
      while (!menu_number && !disp.is_closed() && !disp.is_keyQ() && !disp.is_keyESC()) {

	    img*=0.85f; img+=back;

		// Display foreground text
        const unsigned char *ptrs = fore.data();
        cimg_for(img,ptrd,unsigned char) {
			const unsigned char val = *(ptrs++);
			if (val) *ptrd = val;
		}

		// Display highlight
        const int y = (disp.mouse_y() - y0)/TEXT_HEIGHT, _y = TEXT_HEIGHT*y + y0 + 9;
        if (y >= 0 && y < NUM_OF_ITEMS) {
            img.draw_rectangle(0,_y - 10,0,1,img.width() - 1,_y + 12,0,100,0);
        }
        
        // Set button for the click
        if (disp.button()) {
			menu_number = 1 + (disp.mouse_y() - y0)/TEXT_HEIGHT;
			disp.set_button();
		}

        disp.resize(disp,false).display(img).wait(25);
      }
      start_item(menu_number);
    }
  }

  std::exit(0);
  return 0;
}

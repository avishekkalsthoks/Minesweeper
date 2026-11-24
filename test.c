 for (int y = 0 ; y <HEIGHT;y++){
        for (int x = 0; x<WIDTH;x++){
            if (x<Grid_size || (x>(320-Grid_size)))
            {
                put_pixel(x,y,0xE8E8E8, framebuffer);
            }
            else if (y<Grid_size*2 || y>(200-Grid_size))
            {
                put_pixel(x,y,0xE8E8E8,framebuffer);
            }
            else if (x%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF,framebuffer);
            }
            else if (y%Grid_size==0)
            {
                put_pixel(x,y,0x0000FF,framebuffer);
            }
        }
    }
    for (int i = 0; i<SIZE;i++)
    {
        draw_mine(mines[i].x,mines[i].y,framebuffer);
    }
    for (int i = 0; i< W_BOUND+1; i++){
        for (int j = 0; j < H_BOUND+1; j++){
            if (!in_list_or_not(i,j,mines)){
                switch (num_of_mines(i,j,mines))
                {
                case 0:
                    break;
                case 1:
                    draw_one(i,j,framebuffer);
                    break;
                case 2:
                    draw_two(i,j,framebuffer);
                    break;
                case 3: 
                    draw_three(i,j,framebuffer);
                    break;
                case 4:
                draw_four(i,j,framebuffer);
                    break;
                case 5:
                    draw_five(i,j,framebuffer);
                    break;
                case 6:
                    draw_six(i,j,framebuffer);
                    break;
                case 7:
                    draw_seven(i,j,framebuffer);
                    break;
                case 8:
                    draw_eight(i,j,framebuffer);
                default:
                    break;
                }
            }
        }
        
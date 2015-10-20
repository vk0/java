package ru.csc.java2014.networking.netty;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.*;

import java.nio.charset.StandardCharsets;
import java.util.logging.Level;
import java.util.logging.Logger;


public class EchoClientHandler extends ChannelDuplexHandler {

    private static final Logger LOG = Logger.getLogger(EchoClientHandler.class.getName());

    @Override
    public void write(ChannelHandlerContext ctx, Object msg, ChannelPromise promise) throws Exception {
        String text = (String) msg;
        ctx.write(Unpooled.wrappedBuffer(text.getBytes(StandardCharsets.UTF_8)), promise);
    }


    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        String text = ((ByteBuf) msg).toString(StandardCharsets.UTF_8);
        LOG.info("Got response from " + ctx.channel().remoteAddress() + ": " + text);
    }


    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        LOG.log(Level.SEVERE, null, cause);
        ctx.close();
    }
}
